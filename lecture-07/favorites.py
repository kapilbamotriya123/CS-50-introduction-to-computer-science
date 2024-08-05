import csv

favorite = []
with open("small.csv", "r") as file:
    # reader = csv.reader(file)
    reader = csv.DictReader(file)

    for row in reader:
        favorite.append(row)


print(list(favorite[1].keys()))





# favorite = input("favorite: ")
'''for i in range(len(favorite)):
    if favorite[i]['AATG'] == '2':
        print(i) '''
