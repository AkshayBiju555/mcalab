n1=int(input("enter a number"))
n2=int(input("enter another number"))
while n2>0:
    n1,n2=n2,n1%n2
print("gcd =",n1)