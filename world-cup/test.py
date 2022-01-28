
import csv
import sys
import random

teams = []
# TODO: Read teams into memory from file
with open(sys.argv[1]) as file:
    reader = csv.DictReader(file) #gives a dictionary
    rating = row[int("rating")]

    teams.append(reader)

    print(reader[ratings])


#countries = {"Norway":"1915"}
#print(countries[Norway])