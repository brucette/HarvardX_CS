
import csv
import sys
import random

#python dna.py databases/small.csv sequences/5.txt
# f.read for dna file?

database = [] #argv[1]
database2 = [] #argv[1]
dna = [] #argv[2]

# Read database file into a variable
with open(sys.argv[1], "r") as file:
    reader = csv.DictReader(file) #gives a dictionary
    for row in reader:
        database.append(row)

print()
print("DICTREADER")
for i in range(len(database)):
    print(database[i]) #newdict[0]) #["rating"]
print()
print(database)
print(f"length: {len(database)}")

# Read database file into a variable
with open(sys.argv[1]) as file:
    reader = csv.reader(file) #gives a list
    next(reader)
    for row in reader:
        database2.append(row)

print()
print("READER")
for i in range(len(database2)):
    print(database2[i])
print()
print(database2)

with open(sys.argv[2], "r") as f:
        genes = f.read()
        dna.append(genes)


print()
for i in range(0, len(dna)):
    print(dna[i], " ")

print()
print(len(dna))


def longest_match(dna, AGATC):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence) #5
    sequence_length = len(sequence) #171

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length): #171

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length #0
            end = start + subsequence_length #5

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run








