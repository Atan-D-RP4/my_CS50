from um import count

def test_count():
    test_dict = {
        "um": 1,
        "Hello, um, world!": 1,
        "um, um, um": 3,
        "This,umm, is, um... CS50.": 1,
        "Um, uM, uM, um": 4,
    }

    for key, value in test_dict.items():
        assert count(key) == value

