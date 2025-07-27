sub1=int(input("Please enter your marks for English: "))
sub2=int(input("Please enter your marks for Alternative English: "))
sub3=int(input("Please enter your marks for Computer Science & Computer Application: "))
sub4=int(input("Please enter your marks for Physics: "))
sub5=int(input("Please enter your marks for Chemistry: "))
sub6=int(input("Please enter your Biology/Mathematics: "))
total_percentage=(sub1+sub2+sub3+sub4+sub5+sub6)/6
print(f"You've scored {total_percentage}% in your final year examination!")
if(sub1<sub2 and sub1<sub3 and sub1<sub4 and sub1<sub5 and sub1<sub6):
    print(f"English: {sub1} is your fourth subject")
    sub1=0
elif(sub2<sub1 and sub2<sub3 and sub2<sub4 and sub2<sub5 and sub2<sub6):
    print(f"Alternative English: {sub2} is your fourth subject")
    sub2=0
elif(sub3<sub1 and sub3<sub2 and sub3<sub4 and sub3<sub5 and sub3<sub6):
    print(f"Computer Science: {sub3} is your fourth subject")
    sub3=0
elif(sub4<sub1 and sub4<sub2 and sub4<sub3 and sub4<sub5 and sub4<sub6):
    print(f"Physics: {sub4} is your fourth subject")
    sub4=0
elif(sub5<sub1 and sub5<sub2 and sub5<sub3 and sub5<sub4 and sub5<sub6):
    print(f"Chemistry: {sub5} is your fourth subject")
    sub5=0
elif(sub6<sub1 and sub6<sub2 and sub6<sub3 and sub6<sub4 and sub6<sub5):
    print(f"Biology/Mathematics: {sub6} is your fourth subject")

final_percentage=(sub1+sub2+sub3+sub4+sub5+sub6)/5
print(f"You have {final_percentage}% obtained")