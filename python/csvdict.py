import csv
mydict=[
    {"first":"Akshay","last":"Biju"},
    {"first":"Akhil","last":"Krishna"},
    {"first":"Sreevidya","last":"Madhu"}
    ]

with open("dict.csv","w") as file:
    writer=csv.DictWriter(file,fieldnames=["first","last"])
    writer.writeheader()
    writer.writerows(mydict)

with open("dict.csv","r") as csvfile:
    file=csv.DictReader(csvfile)
    for row in file:
        print(row)
