"""
For loops are used for sequential traversal. For traversing list, string, tuples etc.

for loops example:

for VARIABLE_NAME in LIST/STRING/TUPLES
    #some work
    -- Here VARIABLE_NAME acts as the place where each sequenctial elements are stored once during a iteration
"""

users = ["Gaurav","Hrishikesh","Rehan", "Nayan", "Jharna"]
for element in users:
    print(element)
else: # This block is used in case if we use break statemnt to break the loop and do not want to be executed.
    print("End of loop")