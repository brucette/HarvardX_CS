import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py DATABASE SEQUENCE")

    datafile = sys.argv[1]
    dnafile = sys.argv[2]

    # Read database file into a variable
    database = []
    with open(datafile, "r") as file:
        reader = csv.DictReader(file) #gives a dictionary
        for row in reader:
            database.append(row)

    # Read DNA sequence file into a variable
    with open(dnafile, "r") as text:
        genes = text.read()
                                                                # len(s) might be useful
    # Find longest match of each STR in DNA sequence            # s[i:j] finds substring
    # Get the STRs to be checked for in the sequence:
    with open(datafile, "r") as file:
        reader = csv.DictReader(file)
        # Get first line(column names) of database
        header = dict(list(reader)[0])
        STRs = list(header.keys())
        # Remove 'name' from list of STRs(colums names) to be checked
        del STRs[0]

    # Check database for matching profiles
    snippets = get_number_of_each_STR(STRs, genes)

    result = check_for_match(snippets, database)
    if result:
        print(result)
    else:
        print("No match.")


def get_number_of_each_STR(list_of_STRs, gene_sequence):
    """Returns as a dict the name of STR and number of how many times
     it repeats consecutively in the DNA sample"""
    snippets = {}
    for code in list_of_STRs:
        snippets[code] = 0
        number = longest_match(gene_sequence, code)
        snippets[code] += number

    return snippets

def check_for_match(snippets, database):
    for entry in database:
        name = entry.pop("name")
        for value in entry:
            entry[value] = int(entry[value])
            if entry == snippets:
                return name
    return False

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



main()
