# TODO


def main():
    string = str(input("Text: "))
    grade_level(string)
    return 0


def grade_level(text):
    letters, words, sentences = 0, 1, 0
    for char in text:
        if char.isalnum():
            letters = letters + 1
        elif char == " ":
            words = words + 1
        elif char in [".", "!", "?"]:
            sentences = sentences + 1
    index = round(
        (0.0588 * ((letters / words) * 100))
        - (0.296 * ((sentences / words) * 100))
        - 15.8
    )
    if index > 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {round(index)}")


if __name__ == "__main__":
    main()
