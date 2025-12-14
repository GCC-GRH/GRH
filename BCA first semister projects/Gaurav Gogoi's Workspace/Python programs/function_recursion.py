def show(a):
    if(a==5):
        print(a)
        return
    print(a)
    show(a+1)

show(1)

# Function recursion is the method through which a functions recalls itself untill a given evaluation condition is satisfied. 
# It is similar to a loops in python programming