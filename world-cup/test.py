
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
        print(newdict[0])

def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


while len(simulate_round(teams)) != 1:
     winner = (simulate_round(teams)
return winner






