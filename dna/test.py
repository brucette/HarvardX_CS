
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
with open(sys.argv[1], "r") as file:
    reader = csv.DictReader(file) #gives a dictionary
    #header = csv.reader(file)
    for row in reader:
        database.append(row)

    snippet = list(row[])
        snippets.append(row)

print()
for i in range(len(snippets)):
    print(snippets[i])
#print(header)
#print(database)








