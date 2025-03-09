from seasons import num_in_words

def test_num_in_words():
    test_dict = {
        1999: "one thousand, nine hundred ninety-nine",
        102433: "one hundred two thousand, four hundred thirty-three",
        1000000: "one million",
        1232453: "one million, two hundred thirty-two thousand, four hundred fifty-three",
    }

    for key, value in test_dict.items():
        assert num_in_words(key) == value

