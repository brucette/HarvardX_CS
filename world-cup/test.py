
import csv
import sys
import random

teams = []
# TODO: Read teams into memory from file
with open(sys.argv[1]) as file:
    reader = csv.DictReader(file) #gives a dictionary
    for row in reader:
        newdict = row["team]
        newdict["team"] = int(row[])
        rating = int(row["rating"])
        teams.append(row)
        print(row)


#countries = {"Norway":"1915"}
#print(countries[Norway])