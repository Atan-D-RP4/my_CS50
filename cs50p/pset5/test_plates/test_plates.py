from plates import is_valid

def test_is_valid():
    test_dict = { "CS50": True,
                  "CS05": False,
                  "ECTO88": True,
                  "ECT-088": False,
                  "ECT 088": False,
                  "NRVOUS": True,
                  "50": False,
                  "CS50P2": False,
                  "PI3.14": False,
                  "H": False,
                  "OUTATIME": False
                }
    for key in test_dict:
        assert is_valid(key) == test_dict[key]
