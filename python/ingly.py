s=str(input("enter a string"))
if  s.endswith("ing"):
    s=s+"ly"
else:
    s=s+"ing"
print("new string is:",s)