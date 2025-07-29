def factorial(n):
    result=1
    for i in range(1, n): 
        result*=i  
        print(i)
    return result

n=int(input("Please enter a number to find its factorial:"))
print(factorial(n))
