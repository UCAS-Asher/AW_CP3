from tabulate import tabulate

data = [["Mustard", "Blud", 67], ["Mango", "Blud", 67]]

print(tabulate(data, ["Name", "Job", "Networth"]))