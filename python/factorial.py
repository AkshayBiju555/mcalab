num=int(input("enter the number to find factorial"))
fact=1
for i in range(1,num+1):
    fact=fact*i
    
print("factorial of",num,"is",fact)