string=input("enter a sentence ")
a=[]
count=0
a=string.split()
for char in a:
    for i in range(0,len(a)):

        if char==a[i]:
            count=count+1
    print("the occurence of",char,"is",count,"times")
    count=0
