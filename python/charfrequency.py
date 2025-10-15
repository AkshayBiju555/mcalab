s=input("enter a string:")
freq={}
for char in s:
    #print("number of times",char)
    if char in freq:
        freq[char]+=1
        
    else:
        freq[char]=1
    #print("occurs is",freq[char])
    #print("number of times",char,"occurs is",freq[char])

print(freq)
