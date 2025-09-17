num=list(map(int,input("enter integers").split()))
pos=[]
print("positive numbers in list are")
for i in num:
    
    if i>0:
        pos.append(i)
print(pos)

neg=[]
print("negative numbers in list are")
for i in num:
    
    if i<0:
        neg.append(i)
print(neg)

