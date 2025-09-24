word=input("enter a word:")
vow=['a','e','i','o','u','A','E','I','O','U']
lis=[]
for char in word:
    if char in vow:
        lis.append(char)
print("The vowels are ",lis)