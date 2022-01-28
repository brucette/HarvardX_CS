
import csv
import sys
import random

teams = []
# TODO: Read teams into memory from file
with open(sys.argv[1]) as file:
    reader = csv.DictReader(file) #gives a dictionary
    for row in reader:
        rating = int(rating)
        newdict = row["team"], row[("rating")]
        teams.append(newdict)
        print(newdict)


#countries = {"Norway":"1915"}
#print(countries[Norway])