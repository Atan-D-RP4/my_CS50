# Finished


def main():
    ccn = get_card_no()
    if ccn_validity(ccn):
        show_card_brand(ccn)
    else:
        print("INVALID")
        return 0


# Gets Credit Card Number from User
def get_card_no():
    while True:
        ccn = int(input("Card Number: " + "\n"))
        if ccn > 0:
            return ccn


# Evaluates the Length of Credit Card Number
def ccn_length(ccn):
    count = 0
    while ccn > 0:
        ccn = ccn // 10
        count = count + 1
    return count


# Evaluates the Brand of the Card
def show_card_brand(ccn):
    if (ccn >= 4e12 and ccn < 5e12) or (ccn >= 4e15 and ccn <= 5e15):
        print("VISA")
    elif (ccn >= 34e13 and ccn <= 35e13) or (ccn >= 37e13 and ccn <= 38e13):
        print("AMEX")
    elif (ccn >= 51e14) and (ccn < 56e14):
        print("MASTERCARD")
    else:
        print("INVALID")


# Validates the Credit Card Number using Luhn's Algortihm
def ccn_validity(ccn):
    i = 0
    _sum = 0
    digit = 0
    ccn_len = ccn_length(ccn)
    while ccn != 0:
        if i % 2 == 0:
            _sum += ccn % 10
        else:
            digit = (ccn % 10) * 2
            _sum += (digit % 10) + (digit // 10)
        i = i + 1
        ccn //= 10
    return (_sum % 10 == 0) and ((ccn_len) == 13 or (ccn_len) == 15 or (ccn_len) == 16)


if __name__ == "__main__":
    main()
