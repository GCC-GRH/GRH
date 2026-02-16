#WAP a program to store 9 and 9.0 in the same set
values={9,"9.0"} #First possible solution. Storing the value of 9.0 as string
print(values)
# Second possible solution is
values={
    ("int",9),("float",9.0)
}
print(values)