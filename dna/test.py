
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
    header = dict(list(reader)[0])
    STRs = list(header.keys())
    del STRs[0]

with open(sys.argv[1], "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        database.append(row)

snippets = {}
for code in STRs:
    snippets[code] = 0

dna = []
with open(sys.argv[2], "r") as f:
    genes = f.read()
    dna.append(genes)

print()

print(f"genes: {genes}")
#print(type(genes))
#print(f"dna: {dna}")
#print(type(dna))
print(f"STRs: {STRs}")
print(f"final STRs: {final_STRs}")
#print(f"Snippets: {snippets}")
#print(f"Reader: {reader}")
#print(f"database: {database}")
#print(f"headers: {header}")
#for i in range(1, len(list_of_column_names)):
    #print(list_of_column_names[i])








