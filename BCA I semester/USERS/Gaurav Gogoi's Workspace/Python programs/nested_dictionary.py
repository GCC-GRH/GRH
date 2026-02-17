

# definition of a nested dictionary as sub-dictionary in a parent dictionary.
parent_dict={
    "name" : "Gaurav gogoi",
    "class": 12,
    "marks_sub_dict" : {
        "English" : 79,
        "Alternative english" : 76,
        "Physics" : 57,
        "Computer Science and Computer Application" : 83,
        "Mathematics" : 42

    }
}

#Methods of accessing nested dictionary key values.
print(parent_dict["marks_sub_dict"]["English"]) #Accessing Sub-dictionary key values
print(parent_dict["marks_sub_dict"]) #Accessing Sub-Dictionary as a whole