# This program prints the multiplications of a given number table
n=int(input("You want to print the multiplication of which table ? \n"))
i=1
while i<=10:
    multiple=n*i
    print(f"{n} X {i} = {multiple}")
    i+=1
print("End of the loop program") 