from tkinter import *
body=Tk()
body.title("Entry using Tkinter")
body.minsize(1280,720)
text1=Label(body,text='First name:').grid(row=0)
text2=Label(body,text='Last name:').grid(row=1)
e1=Entry(body)
e2=Entry(body)
e1.grid(row=0,column=1)
e2.grid(row=1,column=1)






body.mainloop()