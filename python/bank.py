class Bank:
    def __init__(this,name,acc_no,balance):
        this.name=name
        this.acc_no=acc_no
        this.balance=balance
    
    def deposit(this,amount):
        this.amount=amount
        print(f"deposited amount is Rs{amount}")
        this.balance+=this.amount
        print(f"current balance amount is Rs{this.balance}")
#balance and name are attributes of bank class so use this to refer them always
    
    def withdraw(this, amount):
        if amount > this.balance:
            print("Insufficient balance!")
        else:
            this.balance -= amount
            print(f"Withdrew ₹{amount}")
    
    def dis_balance(this):
        print(f"the current balance is Rs{this.balance}")

name=input("enter your name")
acc_no=int(input("enter the account number:"))
balance1=float(input("enter your current balance"))
account=Bank(name,acc_no,balance1)

deposit_amount = float(input("Enter amount to deposit: ₹"))
account.deposit(deposit_amount)

withdraw_amount = float(input("Enter amount to withdraw: ₹"))
account.withdraw(withdraw_amount)

account.dis_balance()