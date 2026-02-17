# A Checkbox is a box which can be toggled on or off. It can be linked to a variable to store its state.
from tkinter import *
root=Tk()
root.minsize(1280,720)
root.title("Use of checkboxes in python")
check_state1=IntVar() #Variable typecasting
check_state2=IntVar() #Variable typecasting
checkbox1=Checkbutton(root, variable=check_state1,text='Female').grid(row=0,sticky=W)
checkbox2=Checkbutton(root,variable=check_state2,text='Male').grid(row=1,sticky=W)










root.mainloop()