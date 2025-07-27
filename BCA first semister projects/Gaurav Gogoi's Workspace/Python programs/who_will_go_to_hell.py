n=int(input("How many numbers of participants would you like to add?"))
users=set()
i=1 #iterator
while i<=n:
    users.add(input(f"Please enter name no.{i}"))
    i+=1
users.pop()
print(f"The user who will not go to hell are {users}")
users.clear()