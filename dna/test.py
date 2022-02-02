
import csv
import sys
import random

database = []
dna = []

# TODO: Read teams into memory from file
with open(sys.argv[1]) as file:
    reader = csv.DictReader(file) #gives a dictionary
    for row in reader:
        int(row["rating"])
        teams.append(row)

for i in range(len(teams)):
    print(teams[i]["rating"]) #newdict[0])










