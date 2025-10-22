class Bank:
    def __init__(this,name,balance):
        this.name=name
        this.balance=balance
    
    def deposit(this,amount):
        this.amount=amount
        print(f"deposited amount is Rs{amount}")
    
    def withdraw(this, amount):
        if amount > this.balance:
            print("Insufficient balance!")
        else:
            this.balance -= amount
            print(f"Withdrew ₹{amount}")
    
    def dis_balance(this):
        print(f"the current balance is Rs{this.balance}")

name=input("enter your name")
balance1=float(input("enter your current balance"))
account=Bank(name,balance1)

deposit_amount = float(input("Enter amount to deposit: ₹"))
account.deposit(deposit_amount)

withdraw_amount = float(input("Enter amount to withdraw: ₹"))
account.withdraw(withdraw_amount)

account.dis_balance()