import csv
with open('/workspaces/127962702/dna/databases/small.csv', newline='') as f:
    reader = csv.reader(f)
    for row in reader:
        print(row[2])
