from cs50 import get_string

text = get_string("Text: ")


letters = 0
words = 0
sentences = 0

for character in text:
    letter = ord(character.lower())
                #97        122
    if letter >= 'a' and letter <= 'z':
        letters += 1

    if character == " ":
        words += 1

    if character == '.' or == '!' or === '?':
        sentences += 1

print(letters, words, sentences)




# 0.0588 * L - 0.296 * S - 15.8,
# where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text

