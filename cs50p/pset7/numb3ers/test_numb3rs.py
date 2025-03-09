from numb3rs import validate

def test_validate():
    # test cases for IPv4 addresses
    test_cases = { "12.34.12.00": True,
                   "cat": False,
                   "10.10.10.10.10": False,
                   "2001.21.244.54": False,
                   "8.8.8": False,
                   "255.255.255.255": True,
                   "23.256.256.256": False,
                 }
    for test_case in test_cases:
        assert validate(test_case) == test_cases[test_case]
