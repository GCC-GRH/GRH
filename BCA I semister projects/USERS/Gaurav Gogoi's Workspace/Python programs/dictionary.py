# This program fascillates the used of dictionary in python language.
# Data items are stored in key : value pair.
# Dictionaries are mutable, unordered and do not accept duplicate keys like an actual Dictionary.
myDict={
    "name" : "Gaurav gogoi",
    "age" : 20,
    "Degree" : "Bachelor in Computer Application"
}
print(myDict) #This technique is used to fetch the whole dictionary.
print(myDict["name"]) #This technique is used to fetch value of a key within a dictionary.
#Since Dictionaries are mutable, we can initialise new data item or modify exisitng ones.
myDict["Laptop"]=True #Adding of new key:value paired data item in the existing Dictionary.
print(myDict)
# Modifying existing key:value pairs
myDict["Laptop"]=False
print(myDict)

# We can also store List and Tuples within a dictionary
newdict={
    "List" : [1,2,3,4,5,"meow"],
    "Tuple" : (1,2,3,4,5,"meow")
}
print(newdict)
print(newdict["List"])
print(newdict["Tuple"])


# To declare a null Dictionary, we use the parenthesis symbol.
null_dict={}
print(null_dict)