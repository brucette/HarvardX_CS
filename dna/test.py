
import csv
import sys
import random

#python dna.py databases/small.csv sequences/5.txt

database = [] #argv[1]
database2 = [] #argv[1]
dna = [] #argv[2]

# Read database file into a variable
with open(sys.argv[1]) as file:
    reader = csv.DictReader(file) #gives a dictionary
    for row in reader:
        database.append(row)

print()
print("DICTREADER")
for i in range(len(database)):
    print(database[i]) #newdict[0]) #["rating"]

# Read database file into a variable
with open(sys.argv[1]) as file:
    reader = csv.reader(file) #gives a list
    next(reader)
    for row in reader:
        database2.append(row)

print()
print("READER")
for i in range(len(database2)):
    print(database2[i])











