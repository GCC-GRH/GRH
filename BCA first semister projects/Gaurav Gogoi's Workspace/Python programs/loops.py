"""
Loops in python are used to repeat instructions
There are two types of loops in python, they are:
1. while
2. for

Unlike loops in C and C++, we use indentations to define a loop body followed by : to mark the begin of the loop code block

"""
# 1. Use of while loop in Python programming
n=int(input("How many times would you like to perform iterations? "))
i=1 #Iterator used to define a starting point and also used as a loop counter
while i<=n :
    print("Hello world")
    i+=1
print("End of loop")