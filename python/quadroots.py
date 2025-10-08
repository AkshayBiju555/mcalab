import math
a=int(input("enter coefficient of a"))
b=int(input("enter coefficient of b"))
c=int(input("enter coefficient of c"))
d=b**2-4*a*c
if d>0:
    root1=(-b+math.sqrt(d))/(2*a)
    root2=(-b-math.sqrt(d))/(2*a)
    print("roots are real and distinct")
    print("root1=",root1)
    print("root2=",root2)
elif d==0:
    root=-b/(2*a)
    print("roots are real and  equal")
    print("root=",root)
else:
    real_part=(-b)/(2*a)
    imaginary_part=math.sqrt(-d)/(2*a)
    print("roots are complex")
    print(f"root1={real_part}+{imaginary_part}i")
    print(f"root2={real_part}-{imaginary_part}i")
