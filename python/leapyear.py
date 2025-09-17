from datetime import datetime
year1 = datetime.now().year
year2=int(input("enter final  year"))
for i in range(year1,year2+1):
    if (i % 400 == 0) or (i% 4 == 0 and i % 100 != 0):
        print("%d is a leap year",i)
