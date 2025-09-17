word=input("enter a word:")
vow=['a','e','i','o','u']
lis=[]
for char in word:
    if char in vow:
        lis.append(char)
print(lis)