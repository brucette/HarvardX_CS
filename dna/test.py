
import csv
import sys
import random

#python dna.py databases/small.csv sequences/5.txt

database = [] #argv[1]
dna = [] #argv[2]

# Read database file into a variable
with open(sys.argv[1]) as file:
    reader = csv.DictReader(file) #gives a dictionary
    for row in reader:
        database.append(row)

for i in range(len(database)):
    print(teams[i]["rating"]) #newdict[0])

# Read database file into a variable
with open(sys.argv[1]) as file:
    reader = csv.reader(file) #gives a list
    for row in reader:
        database.append(row)












