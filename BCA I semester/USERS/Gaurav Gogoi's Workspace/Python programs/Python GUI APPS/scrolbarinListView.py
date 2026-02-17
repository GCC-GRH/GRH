# What is a listbox?
# It displays a list of items from which a user can select one or more
from tkinter import *
program_body=Tk()
program_body.title('Listbox usage in Python Program')

scrollView1=Scrollbar(program_body)
scrollView1.pack(side=RIGHT,fill=Y)
listbox1=Listbox(program_body,yscrollcommand=scrollView1)
for i in range(1,100) :
    listbox1.insert(i,f'This is line no. {i}')
    
listbox1.pack(side=RIGHT,fill=BOTH,)
scrollView1.config(command=listbox1.yview)
program_body.mainloop()