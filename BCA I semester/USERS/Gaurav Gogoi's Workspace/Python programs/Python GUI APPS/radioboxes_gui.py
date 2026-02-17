"""
What are radioboxes? What makes it different then a checkboxes?
==> Radioboxes are used to choose an option out of given options. It is different then a checkbox because it only provides one selection to a user.
Radioboxes looks circular in gui, where a checkbox is a square.
"""
from tkinter import *
root=Tk()
root.title("Use of RadioBoxes in GUI python Program")
root.minsize(1280,720)
option=IntVar()
text1=Label(root,text='Want to exit this program?').pack()
rad1=Radiobutton(root,text='Yes, leave',variable=option,value=1)
rad1.pack()
rad2=Radiobutton(root,text='No, stay',variable=option,value=2)
rad2.pack()
root.mainloop()
