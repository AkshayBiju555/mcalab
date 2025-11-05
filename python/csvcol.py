import pandas as pd
columns = ["age"]
file = pd.read_csv("data.csv", usecols=columns)
print(file)
