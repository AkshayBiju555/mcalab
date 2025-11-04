import csv
csv_path="file.csv"
with open(csv_path,'r',newline='') as file:
    reader=csv.reader(file)
    for row in reader:
        print(row)