marks={}
print(type(marks))
x=int(input("Enter your marks in English : "))
marks.update({"English" : x})
x=int(input("Enter your marks in Alt : "))
marks.update({"Alternative English" : x})
x=int(input("Enter your marks in Computer Science : "))
marks.update({"Computer Science": x})
print(marks)