from tkinter import *
root= Tk(className='LoudWave')
w = Label(root, text='GeeksForGeeks.org!')
w.pack()
root.minsize(1280,720)
e1=Entry(root,)
button1= Button(root,text='Start session',command=root.destroy)
button1.pack()



root.mainloop()