
import csv
import sys
import random

#python dna.py databases/small.csv sequences/5.txt
# f.read for dna file?

database = [] #argv[1]
snippets = []
database2 = [] #argv[1]
dna = [] #argv[2]

# Read database file into a variable
file = open(sys.argv[1], "r")

reader = csv.DictReader(file) #gives a dictionary
header = csv.DictReader(file)
header = dict(list(reader)[0])
list_of_column_names = list(header.keys())
for row in reader:
        database.append(row)

#with open(sys.argv[1], "r") as file:
    #reader = csv.DictReader(file)


print()
print(list_of_column_names)
for i in range(len(database)):
    print(database[i])








