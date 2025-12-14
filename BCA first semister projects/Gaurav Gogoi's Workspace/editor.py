#!/usr/bin/env python3
"""
Beautiful Tkinter Code Editor
- New/Open/Save/Save As
- Undo/Redo, Cut/Copy/Paste
- Find & Replace
- Line numbers
- Simple Python syntax highlighting (regex-based)
- Light/Dark theme toggle
- Run current file (captures stdout/stderr)
- Status bar showing line/col and file name

Run: python3 beautiful_tkinter_code_editor.py
"""

import tkinter as tk
from tkinter import ttk, filedialog, messagebox, simpledialog, font
import os
import sys
import subprocess
import threading
import re

PY_KEYWORDS = r"\b(False|None|True|and|as|assert|async|await|break|class|continue|def|del|elif|else|except|finally|for|from|global|if|import|in|is|lambda|nonlocal|not|or|pass|raise|return|try|while|with|yield)\b"

class CodeEditor(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("Beautiful Tkinter Code Editor")
        self.geometry("1000x700")
        self._file_path = None
        self._saved = True

        self._create_styles()
        self._create_widgets()
        self._bind_shortcuts()
        self._apply_theme('dark')

    def _create_styles(self):
        self.style = ttk.Style(self)
        # Use default theme but small tweaks can be done here

    def _create_widgets(self):
        # Menu
        self._create_menu()

        # Paned layout: editor on top, output below
        self.paned = ttk.Panedwindow(self, orient=tk.VERTICAL)
        self.paned.pack(fill=tk.BOTH, expand=True)

        # Editor frame
        editor_frame = ttk.Frame(self.paned)
        self.paned.add(editor_frame, weight=3)

        # Line numbers canvas
        ln_frame = ttk.Frame(editor_frame)
        ln_frame.pack(side=tk.LEFT, fill=tk.Y)
        self.line_numbers = tk.Text(ln_frame, width=4, padx=4, takefocus=0, border=0, background='#2b2b2b', foreground='#8c8c8c', state='disabled')
        self.line_numbers.pack(fill=tk.Y)

        # Text widget with scrollbar
        text_frame = ttk.Frame(editor_frame)
        text_frame.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)

        self.text = tk.Text(text_frame, wrap='none', undo=True, autoseparators=True, maxundo=-1)
        self.text.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)

        yscroll = ttk.Scrollbar(text_frame, orient=tk.VERTICAL, command=self._on_vscroll)
        yscroll.pack(side=tk.LEFT, fill=tk.Y)
        self.text.config(yscrollcommand=yscroll.set)

        xscroll = ttk.Scrollbar(self, orient=tk.HORIZONTAL, command=self.text.xview)
        xscroll.pack(fill=tk.X)
        self.text.config(xscrollcommand=xscroll.set)

        # Configure font
        self.font_family = 'Consolas' if 'Consolas' in font.families() else 'Courier'
        self.font_size = 12
        self.text.configure(font=(self.font_family, self.font_size))
        self.line_numbers.configure(font=(self.font_family, self.font_size))

        # Syntax highlighting tags
        self.text.tag_configure('keyword', foreground='#cc7832')
        self.text.tag_configure('string', foreground='#6A8759')
                self.text.tag_configure('number', foreground='#6897BB')
        self.text.tag_configure('builtin', foreground='#FFC66D')
        italic_font = font.Font(self.text, self.text.cget("font"))
italic_font.configure(slant="italic")
self.text.tag_configure('comment', foreground='#808080', font=italic_font)


        # Bottom: output/console
        console_frame = ttk.Frame(self.paned)
        self.paned.add(console_frame, weight=1)
        console_label = ttk.Label(console_frame, text='Console Output')
        console_label.pack(anchor='w')

        self.console = tk.Text(console_frame, height=10, state='disabled')
        self.console.pack(fill=tk.BOTH, expand=True)

        # Status bar
        self.status = ttk.Label(self, text='Line 1, Col 1 — Untitled', anchor='w')
        self.status.pack(fill=tk.X)

        # Events
        self.text.bind('<<Modified>>', self._on_modified)
        self.text.bind('<KeyRelease>', self._on_key_release)
        self.text.bind('<ButtonRelease>', self._update_line_numbers)
        self.text.bind('<MouseWheel>', lambda e: self._update_line_numbers())
        self.text.bind('<Configure>', lambda e: self._update_line_numbers())

        # Initialize
        self._update_line_numbers()

    def _create_menu(self):
        menubar = tk.Menu(self)
        # File
        filem = tk.Menu(menubar, tearoff=0)
        filem.add_command(label='New', accelerator='Ctrl+N', command=self.new_file)
        filem.add_command(label='Open...', accelerator='Ctrl+O', command=self.open_file)
        filem.add_command(label='Save', accelerator='Ctrl+S', command=self.save)
        filem.add_command(label='Save As...', accelerator='Ctrl+Shift+S', command=self.save_as)
        filem.add_separator()
        filem.add_command(label='Exit', command=self.on_close)
        menubar.add_cascade(label='File', menu=filem)

        # Edit
        editm = tk.Menu(menubar, tearoff=0)
        editm.add_command(label='Undo', accelerator='Ctrl+Z', command=lambda: self.text.event_generate('<<Undo>>'))
        editm.add_command(label='Redo', accelerator='Ctrl+Y', command=lambda: self.text.event_generate('<<Redo>>'))
        editm.add_separator()
        editm.add_command(label='Cut', accelerator='Ctrl+X', command=lambda: self.text.event_generate('<<Cut>>'))
        editm.add_command(label='Copy', accelerator='Ctrl+C', command=lambda: self.text.event_generate('<<Copy>>'))
        editm.add_command(label='Paste', accelerator='Ctrl+V', command=lambda: self.text.event_generate('<<Paste>>'))
        editm.add_separator()
        editm.add_command(label='Find & Replace', accelerator='Ctrl+F', command=self.find_replace)
        menubar.add_cascade(label='Edit', menu=editm)

        # View
        viewm = tk.Menu(menubar, tearoff=0)
        viewm.add_command(label='Toggle Theme', command=self._toggle_theme)
        viewm.add_command(label='Font...', command=self._choose_font)
        menubar.add_cascade(label='View', menu=viewm)

        # Run
        runm = tk.Menu(menubar, tearoff=0)
        runm.add_command(label='Run (Python)', accelerator='F5', command=self.run_current_file)
        menubar.add_cascade(label='Run', menu=runm)

        self.config(menu=menubar)

    # ---------------- File operations ----------------
    def new_file(self):
        if not self._confirm_save():
            return
        self.text.delete('1.0', tk.END)
        self._file_path = None
        self._saved = True
        self._update_title()
        self._apply_highlighting()

    def open_file(self):
        if not self._confirm_save():
            return
        path = filedialog.askopenfilename(filetypes=[('Python Files', '*.py'), ('All Files', '*.*')])
        if path:
            with open(path, 'r', encoding='utf-8') as f:
                data = f.read()
            self.text.delete('1.0', tk.END)
            self.text.insert('1.0', data)
            self._file_path = path
            self._saved = True
            self._update_title()
            self._apply_highlighting()
            self._update_line_numbers()

    def save(self):
        if self._file_path:
            self._write_file(self._file_path)
        else:
            self.save_as()

    def save_as(self):
        path = filedialog.asksaveasfilename(defaultextension='.py', filetypes=[('Python Files', '*.py'), ('All Files', '*.*')])
        if path:
            self._write_file(path)
            self._file_path = path
            self._update_title()

    def _write_file(self, path):
        try:
            with open(path, 'w', encoding='utf-8') as f:
                f.write(self.text.get('1.0', tk.END).rstrip() + '\n')
            self._saved = True
            self._update_title()
            self._append_console(f"Saved {path}\n")
        except Exception as e:
            messagebox.showerror('Save Error', str(e))

    def _confirm_save(self):
        if not self._saved:
            res = messagebox.askyesnocancel('Unsaved Changes', 'You have unsaved changes. Save before continuing?')
            if res is None:
                return False
            if res:
                self.save()
                return self._saved
        return True

    def on_close(self):
        if not self._confirm_save():
            return
        self.destroy()

    # ---------------- UI helpers ----------------
    def _update_title(self):
        name = os.path.basename(self._file_path) if self._file_path else 'Untitled'
        star = '' if self._saved else '*'
        self.title(f"{name}{star} - Beautiful Editor")
        self.status.config(text=f"{name} — Line {self._get_cursor_line()}, Col {self._get_cursor_col()}")

    def _get_cursor_line(self):
        return int(self.text.index(tk.INSERT).split('.')[0])

    def _get_cursor_col(self):
        return int(self.text.index(tk.INSERT).split('.')[1]) + 1

    # ---------------- Events ----------------
    def _on_modified(self, event=None):
        if self.text.edit_modified():
            self._saved = False
            self._update_title()
            self._apply_highlighting()
            self._update_line_numbers()
            self.text.edit_modified(False)

    def _on_key_release(self, event=None):
        self._update_title()

    # ---------------- Line numbers ----------------
    def _update_line_numbers(self, event=None):
        lines = int(self.text.index('end-1c').split('.')[0])
        self.line_numbers.config(state='normal')
        self.line_numbers.delete('1.0', tk.END)
        nums = '\n'.join(str(i) for i in range(1, lines+1))
        self.line_numbers.insert('1.0', nums)
        self.line_numbers.config(state='disabled')

    def _on_vscroll(self, *args):
        self.text.yview(*args)
        self.line_numbers.yview(*args)

    # ---------------- Syntax highlighting ----------------
    def _apply_highlighting(self):
        code = self.text.get('1.0', tk.END)
        # Clear tags
        for tag in ['keyword', 'string', 'comment', 'number', 'builtin']:
            self.text.tag_remove(tag, '1.0', tk.END)

        # Comments
        for m in re.finditer(r"#.*", code):
            start = f"1.0+{m.start()}c"
            end = f"1.0+{m.end()}c"
            self.text.tag_add('comment', start, end)

        # Strings (single, double, triple)
        for m in re.finditer(r"(\'(?:\\.|[^\\'])*\'|\"(?:\\.|[^\\\"])*\"|\'\'\'(?:.|\n)*?\'\'\'|\"\"\"(?:.|\n)*?\"\"\")", code):
            start = f"1.0+{m.start()}c"
            end = f"1.0+{m.end()}c"
            self.text.tag_add('string', start, end)

        # Numbers
        for m in re.finditer(r"\b\d+(?:\.\d+)?\b", code):
            start = f"1.0+{m.start()}c"
            end = f"1.0+{m.end()}c"
            self.text.tag_add('number', start, end)

        # Keywords
        for m in re.finditer(PY_KEYWORDS, code):
            start = f"1.0+{m.start()}c"
            end = f"1.0+{m.end()}c"
            self.text.tag_add('keyword', start, end)

        # Builtins (a handful)
        for m in re.finditer(r"\b(len|print|range|open|list|dict|set|int|str|float|super|isinstance|type)\b", code):
            start = f"1.0+{m.start()}c"
            end = f"1.0+{m.end()}c"
            self.text.tag_add('builtin', start, end)

    # ---------------- Find & Replace ----------------
    def find_replace(self):
        dialog = FindReplaceDialog(self)
        self.wait_window(dialog)

    # ---------------- Run code ----------------
    def run_current_file(self):
        if not self._file_path:
            res = messagebox.askyesno('Run Unsaved', 'File needs to be saved to run. Save now?')
            if res:
                self.save_as()
            else:
                return
        # Save before running
        self.save()
        cmd = [sys.executable, self._file_path]
        self._append_console(f"Running: {' '.join(cmd)}\n")
        def target():
            try:
                proc = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
                out, err = proc.communicate()
                if out:
                    self._append_console(out)
                if err:
                    self._append_console(err)
                self._append_console(f"\nProcess exited with {proc.returncode}\n")
            except Exception as e:
                self._append_console(str(e) + '\n')
        threading.Thread(target=target, daemon=True).start()

    def _append_console(self, text):
        self.console.config(state='normal')
        self.console.insert(tk.END, text)
        self.console.see(tk.END)
        self.console.config(state='disabled')

    # ---------------- Theme & Font ----------------
    def _apply_theme(self, name):
        if name == 'dark':
            bg = '#2b2b2b'
            fg = '#ffffff'
            text_bg = '#313335'
            lineno_bg = '#2b2b2b'
            console_bg = '#1e1e1e'
        else:
            bg = '#f5f5f5'
            fg = '#000000'
            text_bg = '#ffffff'
            lineno_bg = '#eeeeee'
            console_bg = '#f0f0f0'

        self.configure(bg=bg)
        self.text.config(background=text_bg, foreground=fg, insertbackground=fg)
        self.line_numbers.config(background=lineno_bg, foreground='#6b6b6b')
        self.console.config(background=console_bg, foreground=fg)

    def _toggle_theme(self):
        current = getattr(self, '_theme', 'dark')
        new = 'light' if current == 'dark' else 'dark'
        self._theme = new
        self._apply_theme(new)

    def _choose_font(self):
        fam = simpledialog.askstring('Font Family', 'Enter font family (e.g. Consolas, Courier):', initialvalue=self.font_family)
        if fam:
            self.font_family = fam
        size = simpledialog.askinteger('Font Size', 'Enter font size (e.g. 12):', initialvalue=self.font_size)
        if size:
            self.font_size = size
        self.text.configure(font=(self.font_family, self.font_size))
        self.line_numbers.configure(font=(self.font_family, self.font_size))

    # ---------------- Utilities ----------------
    def _get_selected_text(self):
        try:
            return self.text.get(tk.SEL_FIRST, tk.SEL_LAST)
        except tk.TclError:
            return ''

    # ---------------- Shortcuts ----------------
    def _bind_shortcuts(self):
        self.bind('<Control-n>', lambda e: self.new_file())
        self.bind('<Control-o>', lambda e: self.open_file())
        self.bind('<Control-s>', lambda e: self.save())
        self.bind('<Control-S>', lambda e: self.save_as())
        self.bind('<Control-f>', lambda e: self.find_replace())
        self.bind('<F5>', lambda e: self.run_current_file())
        self.protocol('WM_DELETE_WINDOW', self.on_close)

class FindReplaceDialog(tk.Toplevel):
    def __init__(self, master):
        super().__init__(master)
        self.title('Find & Replace')
        self.geometry('400x140')
        self.transient(master)
        self.resizable(False, False)

        ttk.Label(self, text='Find:').grid(row=0, column=0, sticky='e', padx=6, pady=6)
        self.find_entry = ttk.Entry(self, width=40)
        self.find_entry.grid(row=0, column=1, padx=6, pady=6)
        ttk.Label(self, text='Replace:').grid(row=1, column=0, sticky='e', padx=6, pady=6)
        self.replace_entry = ttk.Entry(self, width=40)
        self.replace_entry.grid(row=1, column=1, padx=6, pady=6)

        btn_frame = ttk.Frame(self)
        btn_frame.grid(row=2, column=0, columnspan=2, pady=8)
        ttk.Button(btn_frame, text='Find Next', command=self.find_next).pack(side=tk.LEFT, padx=4)
        ttk.Button(btn_frame, text='Replace', command=self.replace_one).pack(side=tk.LEFT, padx=4)
        ttk.Button(btn_frame, text='Replace All', command=self.replace_all).pack(side=tk.LEFT, padx=4)

        self.master = master
        self.last_pos = '1.0'

    def find_next(self):
        needle = self.find_entry.get()
        if not needle:
            return
        idx = self.master.text.search(needle, self.last_pos, tk.END)
        if not idx:
            messagebox.showinfo('Find', 'No more occurrences')
            self.last_pos = '1.0'
            return
        end = f"{idx}+{len(needle)}c"
        self.master.text.tag_remove('sel', '1.0', tk.END)
        self.master.text.tag_add('sel', idx, end)
        self.master.text.mark_set(tk.INSERT, end)
        self.master.text.see(idx)
        self.last_pos = end

    def replace_one(self):
        if self.master.text.tag_ranges('sel'):
            rep = self.replace_entry.get()
            self.master.text.delete(tk.SEL_FIRST, tk.SEL_LAST)
            self.master.text.insert(tk.INSERT, rep)
            self.master._apply_highlighting()

    def replace_all(self):
        needle = self.find_entry.get()
        rep = self.replace_entry.get()
        if not needle:
            return
        content = self.master.text.get('1.0', tk.END)
        new = content.replace(needle, rep)
        self.master.text.delete('1.0', tk.END)
        self.master.text.insert('1.0', new)
        self.master._apply_highlighting()


if __name__ == '__main__':
    app = CodeEditor()
    app.mainloop()
