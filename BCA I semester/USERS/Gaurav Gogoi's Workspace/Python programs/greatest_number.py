num1=int(input("Please enter your first number: "))
num2=int(input("Please enter your second number: "))
num3=int(input("Please enter your third number: "))
if(num1>num2):
    if(num1>num3):
       print(num1,"is greater")
    else:
        print(num3,"is greater")
elif(num2>num3):
    print(num2,"is greater")
else:
    print(num3,"is greater")