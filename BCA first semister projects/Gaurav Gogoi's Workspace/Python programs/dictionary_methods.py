# declaration and initialisation a new dictionary
myDict={
    "Name" : "Gaurav Gogoi",
    "age"  : 20.1,
    
}

"""
Dictionary methods are used to perform various operations on Dictionary data pairs.
Types of methods:
1. myDict.keys() #returns all keys
2. mydict.values() #returns all values of keys
3. mydict.items() #returns all (key,val) pairs as tuples
4. myDict.get("key") #returns value of a key. This method is the same as of the general method for fetching values but using this, it returns "None" in case of an error without breaking the program.
5. myDict.update(newDict)
"""
print(myDict.keys())
print(myDict.values())
tup=myDict.items() #Provides a list of tuples having (key,value) pairs
print(tup)
print(myDict.get("Name")) # This method is same as print(myDict["Name"]), but the only difference is that it doesn't throws any value upon not finding value for that key. It simply returns none.
myDict.update({"Degree":"bca"}) #This method adds new key,value pair in an existing dictionary. It's non return-type method.
print(myDict)