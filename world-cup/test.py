
import csv
import sys
import random

teams = []
# TODO: Read teams into memory from file
with open(sys.argv[1]) as file:
    reader = csv.DictReader(file) #gives a dictionary
    rating = reader[1]

    teams.append(reader[int(ratings)])
    print(reader[ratings])


#countries = {"Norway":"1915"}
#print(countries[Norway])