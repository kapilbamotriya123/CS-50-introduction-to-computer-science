text = input("Text: ")

word_count = 1
sen_count = 0
letter_count = 0

for spaces in text:
    if spaces == " ":
        word_count += 1

for punct in text:
    if punct in (".", "!", "?"):
        sen_count += 1

for letter in text:
    if letter.isalpha():
        letter_count += 1

L = (letter_count/word_count)*100
S = (sen_count/word_count)*100

index = 0.0588 * L - 0.296 * S - 15.8

if index > 16:
    print("Grade 16+")
elif round(index) < 1:
    print("Before Grade 1")
else:
    print(f"Grade {round(index)}")
