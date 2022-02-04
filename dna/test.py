
import csv
import sys


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

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

database = [] #argv[1]


# Read database file into a variable
with open(sys.argv[1], "r") as file:
    reader = csv.DictReader(file) #gives a dictionary
    header = dict(list(reader)[0])
    STRs = list(header.keys())
    del STRs[0]

dna = []
with open(sys.argv[2], "r") as f:
    genes = f.read()
    dna.append(genes)

with open(sys.argv[1], "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        database.append(row)

snippets = {}
for code in STRs:
    snippets[code] = 0
    number = longest_match(genes, code)
    snippets[code] += number
print(snippets)
print()
print(database)

for entry in database:
    print(f"***,{entry.items()}")
    for entry_k, entry_v in entry.items():
        if entry_k in snippets.keys():
            if int(entry_v) == snippets[entry_k]:
                print(entry["name"])
            else:
                print("No Match")





#for key in snippets.keys():
#for i in range(len(STRs)-1):
    #for entry in database:
            #print(entry[key])
        #i = 1
        #while i != len(STRs):
            #if entry[i] == snippets[key] and entry[key+] == snippets[key]:
            #print(entry["name"])

        #if entry[code] == snippets[code]:
            #print(entry["name"])
        #else:
            #print("No Match")

#print(f"genes: {genes}")
#print(type(genes))
#print(f"dna: {dna}")
#print(type(dna))
#print(f"STRs: {STRs}")
#print(f"Snippets: {snippets}")
#print(f"Reader: {reader}")
#print(f"database: {database}")
#print(f"headers: {header}")
#for i in range(1, len(list_of_column_names)):
    #print(list_of_column_names[i])








