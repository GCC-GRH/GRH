def elements(items,idx=0):
    if(idx==len(items)-1):
        print(items[idx])
    else:
        print(items[idx])
        elements(items,idx+1)

values=["Gaurav","Gitartha","Rehan","Hrishikesh","Nayan","Jharna"]
elements(values)
    