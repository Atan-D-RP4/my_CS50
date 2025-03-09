from datetime import date
import sys

ones = [
    "", "one", "two", "three",
    "four", "five", "six",
    "seven", "eight", "nine"
]

teens = [
    "", "eleven", "twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
]
tens = [
    "", "ten", "twenty", "thirty", "forty", "fifty",
    "sixty", "seventy", "eighty", "ninety"
]
hundreds = [
    "", "one hundred", "two hundred", "three hundred", "four hundred",
    "five hundred", "six hundred", "seven hundred", "eight hundred", "nine hundred"
]
thousands = [
    "", "thousand", "million", "billion", "trillion", "quadrillion", "quintillion",
    "sextillion", "septillion", "octillion", "nonillion", "decillion", "undecillion",
    "duodecillion", "tredecillion", "quattuordecillion", "quindecillion", "sexdecillion",
    "septendecillion", "octodecillion", "novemdecillion", "vigintillion"
]


def main():
    dob = input("Date of birth (YYYY-MM-DD): ").strip()
    try:
        minutes = date.today() - date.fromisoformat(dob)
    except ValueError:
        sys.exit("Invalid date format. Please enter the date in the format YYYY-MM-DD")
    minutes = minutes.days * 24 * 60
    minutes =  num_in_words(minutes)  # Call the function to convert the number to words
    # capitalize the first letter of the first word
    minutes = minutes[0].upper() + minutes[1:]
    print(minutes, "minutes")  # 24 hours in a day, 60 minutes in an hour


def num_in_words(num):
    if num == 0:
        return "zero"
    elif num < 10:
        return ones[num]
    elif num < 20:
        return teens[num - 10]
    elif num < 100:
        return tens[num // 10] + ("-" + ones[num % 10] if num % 10 != 0 else "")
    elif num < 1000:
        return hundreds[num // 100] + (" " + num_in_words(num % 100) if num % 100 != 0 else "")
    elif num < 1000000:
        return (
            num_in_words(num // 1000)
            + " " + thousands[1]
            + (", " + num_in_words(num % 1000)
               if num % 1000 != 0 else "")
        )
    else:
        for i in range(2, len(thousands)):
            if num < 1000 ** i:
                return (
                    num_in_words(num // 1000 ** (i - 1))
                    + " " + thousands[i - 1]
                    + (", " + num_in_words(num % 1000 ** (i - 1))
                    if num % 1000 ** (i - 1) != 0 else "")
                )
        return "infinity"


if __name__ == "__main__":
    main()
