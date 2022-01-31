
import csv
import sys
import random

teams = []
# TODO: Read teams into memory from file
with open(sys.argv[1]) as file:
    reader = csv.DictReader(file) #gives a dictionary
    for row in reader:
        newdict = row["team"], int(row["rating"])
        teams.append(newdict)

print(teams) #newdict[0])









