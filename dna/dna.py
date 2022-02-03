import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py DATABASE SEQUENCE")

    # TODO: Read database file into a variable
    database = []

    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            database.append(row)

    # TODO: Read DNA sequence file into a variable
        #dna = []
    with open(sys.argv[2], "r") as f:
        genes = f.read()
        #dna.append(genes)

    # TODO: Find longest match of each STR in DNA sequence
        # len(s) might be useful
        # s[i:j] finds substring

    # Get the STRs to be checked for in the sequence:
    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file) #gives a dictionary
        header = dict(list(reader)[0])
        STRs = list(header.keys())
        # Remove 'name' from list of STRs to be checked
        del STRs[0]

    # TODO: Check database for matching profiles

    snippets = {}
    for code in STRs:
        snippets[code] = 0
        number = longest_match(genes, code)
        snippets[code] += number

        for snippet in snippets:
            for entry in database:
                if entry[code] == snippets[code]:
                    return entry["name"]


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
