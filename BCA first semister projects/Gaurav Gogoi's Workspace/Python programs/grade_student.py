value=input("Enter student marks: ")
marks=int(value)
if(marks>=90):
    grade="A"

elif(marks>=80):
    grade="B"
elif(marks>=70):
    grade="C"
elif(marks<70):
    grade="D"
else:
    grade="Error"

print(grade)