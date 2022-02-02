
import csv
import sys
import random

#python dna.py databases/small.csv sequences/5.txt
# f.read for dna file?

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
print()
print(database)

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
print()
print(database2)

with open(sys.argv[2], "r") as f:
        genes = f.read()
        for i in range(0, len(genes), 4)
        print(len(snippet))
        #dna.append(snippet)

print()
for i in range(len(dna)):
    print(dna[i])
print()
print(dna)










