l=list(map(int,input("enter integers").split()))
for i in l:
    if(i%2==0):
        l.remove(i)
print("the new list is:",l)
        
