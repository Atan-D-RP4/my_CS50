from twttr import shorten

def test_shorten():
    test_dict = { "twitter": "twttr",
                  "facebook": "fcbk",
                  "AEIOU": "",
                  "aeiou": "",
                  "AEIxOU": "x",
                  ",./?": ",./?",
                  "123456": "123456" }
    for key in test_dict:
            assert shorten(key) == test_dict[key]
