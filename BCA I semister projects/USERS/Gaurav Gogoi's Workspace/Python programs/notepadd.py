import tkinter as tk
from tkinter import filedialog, messagebox
import os

# ------------- Functions -------------
def new_file():
    text_area.delete(1.0, tk.END)
    root.title("Untitled - Modern Notepad")

def open_file():
    file_path = filedialog.askopenfilename(filetypes=[("Text Files", "*.txt"), ("All Files", "*.*")])
    if file_path:
        with open(file_path, "r", encoding="utf-8") as file:
            text_area.delete(1.0, tk.END)
            text_area.insert(tk.END, file.read())
        root.title(os.path.basename(file_path) + " - Modern Notepad")

def save_file():
    file_path = filedialog.asksaveasfilename(defaultextension=".txt",
                                             filetypes=[("Text Files", "*.txt"), ("All Files", "*.*")])
    if file_path:
        with open(file_path, "w", encoding="utf-8") as file:
            file.write(text_area.get(1.0, tk.END))
        root.title(os.path.basename(file_path) + " - Modern Notepad")

def cut_text():
    text_area.event_generate("<<Cut>>")

def copy_text():
    text_area.event_generate("<<Copy>>")

def paste_text():
    text_area.event_generate("<<Paste>>")

def about():
    messagebox.showinfo("About", "Modern Notepad\nWindows 11 Style\n© 2025")

def exit_app():
    root.destroy()

# ------------- Window Setup -------------
root = tk.Tk()
root.title("Modern Notepad")
root.geometry("900x550")
root.configure(bg="#f3f3f3")

# ------------- Toolbar -------------
toolbar = tk.Frame(root, bg="#e5e5e5", height=40)
toolbar.pack(fill=tk.X)

btn_new = tk.Button(toolbar, text="📝 New", command=new_file, bg="#e5e5e5", relief=tk.FLAT, font=("Segoe UI", 10))
btn_open = tk.Button(toolbar, text="📂 Open", command=open_file, bg="#e5e5e5", relief=tk.FLAT, font=("Segoe UI", 10))
btn_save = tk.Button(toolbar, text="💾 Save", command=save_file, bg="#e5e5e5", relief=tk.FLAT, font=("Segoe UI", 10))
btn_cut = tk.Button(toolbar, text="✂ Cut", command=cut_text, bg="#e5e5e5", relief=tk.FLAT, font=("Segoe UI", 10))
btn_copy = tk.Button(toolbar, text="📋 Copy", command=copy_text, bg="#e5e5e5", relief=tk.FLAT, font=("Segoe UI", 10))
btn_paste = tk.Button(toolbar, text="📥 Paste", command=paste_text, bg="#e5e5e5", relief=tk.FLAT, font=("Segoe UI", 10))
btn_about = tk.Button(toolbar, text="ℹ About", command=about, bg="#e5e5e5", relief=tk.FLAT, font=("Segoe UI", 10))

for btn in (btn_new, btn_open, btn_save, btn_cut, btn_copy, btn_paste, btn_about):
    btn.pack(side=tk.LEFT, padx=4, pady=4)

# ------------- Text Area -------------
text_area = tk.Text(root, wrap="word", undo=True, font=("Consolas", 12),
                    bg="white", fg="black", insertbackground="black",
                    selectbackground="#cce8ff", padx=10, pady=10, relief=tk.FLAT)
text_area.pack(fill=tk.BOTH, expand=True)

# ------------- Scrollbar -------------
scroll_bar = tk.Scrollbar(text_area, command=text_area.yview)
text_area.configure(yscrollcommand=scroll_bar.set)
scroll_bar.pack(side=tk.RIGHT, fill=tk.Y)

# ------------- Menu Bar -------------
menu_bar = tk.Menu(root)

file_menu = tk.Menu(menu_bar, tearoff=0)
file_menu.add_command(label="New", command=new_file)
file_menu.add_command(label="Open", command=open_file)
file_menu.add_command(label="Save", command=save_file)
file_menu.add_separator()
file_menu.add_command(label="Exit", command=exit_app)
menu_bar.add_cascade(label="File", menu=file_menu)

edit_menu = tk.Menu(menu_bar, tearoff=0)
edit_menu.add_command(label="Cut", command=cut_text)
edit_menu.add_command(label="Copy", command=copy_text)
edit_menu.add_command(label="Paste", command=paste_text)
menu_bar.add_cascade(label="Edit", menu=edit_menu)

help_menu = tk.Menu(menu_bar, tearoff=0)
help_menu.add_command(label="About", command=about)
menu_bar.add_cascade(label="Help", menu=help_menu)

root.config(menu=menu_bar)

root.mainloop()
