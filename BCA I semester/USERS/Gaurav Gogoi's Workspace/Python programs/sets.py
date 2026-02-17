# This program fascillates use of sets from mathematics in python language.
"""
Q.1 What is a set in python?
==> Set is the collection of the unordered items.
Each elements in the set must be unique & immutable.
eg.
Nums={1,2,3,4} # Correct order
sets2={1,2,2,2} # Repeated items, no error.
Output: {1,2}. As we can see, the repeated occurance of an elemnt have been terminated. Only the first occurance are preserved in sets.
"""
numbers={1,2,3,4,5} #Looks same as a dictionary but without any key:value pairs. In sets, an element is key and value simultanously.
print(numbers)
print(type(numbers))

#How to Declare an empty set?
null_set=set() #we cannot use null_set={} as it will result in an empty dictionary
print(null_set)