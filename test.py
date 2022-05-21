
import csv
import sys

CREATE TABLE purchases (id INTEGER PRIMARY KEY NOT NULL, stock TEXT NOT NULL, price FLOAT NOT NULL, shares INTEGER NOT NULL, time DATETIME);

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
#print(snippets)
#print()
#print(database)

for entry in database:
    name = entry.pop("name")
    for value in entry:
        entry[value] = int(entry[value])
    #print(entry)
    #print(snippets)
        if entry == snippets:
            print(name)


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


FINANCE register:

# If tries to get, then display a form so they can register
    if request.method == "GET":

        return render_template("register.html")

    # Else check for possible errors
    else:

        username = request.form.get("username")
        password = request.form.get("password")
        verify_password = request.form.get("verify_password")

        # Ensure username was submitted
        if not username:
            return apology("must provide username", 403)

        # Ensure username not already taken
        usernames = db.execute("SELECT username FROM users")
        if username in usernames:
            return apology("username is already taken", 403)

        # Ensure password was submitted
        elif not password:
            return apology("must provide password", 403)

        # Ensure password matches verification
        elif not verify_password or password != verify_password:
            return apology("password must match verification", 403)

    # Insert new user into USERS table
    hash_password = generate_password_hash(password)
    db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hash_password)

    session["user_id"] = db.execute("SELECT id FROM users WHERE username = ?", username)

    # Redirect user to home page
    return redirect("/")




