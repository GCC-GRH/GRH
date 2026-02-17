# List is a data type that is used for storing mutitple values of multiple data types referenced under one variable. It's like a variable of variables and similar to arrays. 
#Except that its data type assignment is dynamic 
marks=[90,30,42,43]
print(marks)

# Indexing used in list.
# Indexing is used to fetch and reference the value of a list at a particular position
print(marks[2])

# List slicing technique is used to fetch parts of list values or form a sublist which will be the subset of the list it is made
print(marks[2:3])
# Negative list slicing technique is used to fetch a list from the end point. This technique is used when we are not aware of the end index
print(marks[-2:-1])
#list funtions : List functions are used to perform various operations of given set of list values
marks.append(51)
print(marks)
marks.insert(1,21)
print(marks)
marks.sort()
print(marks)
marks.sort(reverse=True)
print(marks)
marks.reverse()
print(marks)

# List item assignment = In python programming language, we can assign values or reassign list item by refering to thier index number. eg, list=list_item[8]=2 
marks[5]=89
print(marks)


# Difference between list and tuple:
# Lists are mutable, meaning their elements can be changed after creation.
# Tuples are immutable, meaning their elements cannot be changed once assigned.
# Example of a tuple:
my_tuple = (1, 2, 3)
print(my_tuple)
single_tuple=(1,)
print(single_tuple)
#tuple operations used

print(my_tuple.index(3))
print(my_tuple.count(1))
# Trying to modify a tuple will result in an error:
# my_tuple[0] = 10  # This will raise a TypeError
single_list=[1]
print(single_list)