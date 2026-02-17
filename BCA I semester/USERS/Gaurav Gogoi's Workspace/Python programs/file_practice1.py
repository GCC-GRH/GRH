
# Write a program to create a new file named "practice.txt" and add some data in it:
    #filer=open("practice.txt","w")
    #filer.write("Hi everyone\nWe are learning File I/O\nusing Java\nI like programming in Java")
    #filer.close()
# Reopening of the data file and fetch the content in read-mode
    #read_file=open("practice.txt")
    #contents=read_file.read()
    #print(contents)
    #read_file.close()

# Write a function to replace all occurances of "Java" within the existing value of data file
with open("practice.txt") as filer:
    data=filer.read()
    data=data.replace("Java", "Python")
    print(data) 
    if data.count("learning") != 0 :
        print("The word exist")
    else:
        print("Word doesn't exist!")
    