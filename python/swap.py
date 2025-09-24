def swap(x,y):
    temp=x
    x=y
    y=temp
    return x,y

x=input("enter a number")
y=input("enter another number")
print("before swapping x:",x,"y:",y)
x,y=swap(x,y)
print("the swapped inputs are: x:",x,"y:",y)


