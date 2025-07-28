elements=[1,4,9,16,25,36,49,64,81,100]
list_indexes=len(elements)-1
x=int(input("Please enter the value you would like to search within the list ==> "))
i=0
status=0
while i<=list_indexes:
    if elements[i]==x :
        print(f"Element found at {i}th position")
        status=1
        break
    else :
        print("Traversing your list, Please wait!")
        


    i+=1
if(status==0):
    print("NOT found")
else :
    print("Successful end of loop!")