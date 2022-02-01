from cs50 import get_string

text = get_string("Text: ")

letters = 0
#for last word
words = 1
sentences = 0

for character in text:
    letter = ord(character.lower())
               # ascii: 97 = 'a', 122 = 'z'
    if letter >= 97 and letter <= 122:
        letters += 1

    if character == " ":
        words += 1

    if character == '.' or character == '!' or character == '?':
        sentences += 1

# Calculate average number of letters per 100 words
L = int((letters / words) * 100)

# Calculate average number of sentences per 100 words
S = int((sentences / words) * 100)

# Calculate reading grade
grade = int(0.0588 * L - 0.296 * S - 15.8)

if grade >= 16:
    print(f"Grade 16+")

if grade < 1:
    print("Before Grade 1")

else:
    print(f"Grade {grade}")