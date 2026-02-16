class account:
    def __init__(self,name,id):
        print(f"Savings Account opened at memory {self} for user {name} with holder id {id}")
        self.balance=0
    def debit(self):
        if(self.balance!=0) : 
            self.balance-=int(input("Please enter the amount to be debited : "))
            print(f"Amount debited successfully! \n Your current balance is {self.balance}")
        else:
            print("Bank balance is 0")

    def credit(self):
        self.balance+=int(input("Please enter the amount to deposit :"))
        print(f"Amount credited sucessfully! \n Your current balance is {self.balance}")
exit_code=0
user1=account("Gaurav",10120)
while (exit_code!=1) : 
    
    user1.credit()
    user1.debit()
    exit_code=int(input("Would you like to exit ? \n Enter 1 to quit program else restart without losing data: "))