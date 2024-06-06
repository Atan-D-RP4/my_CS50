from fuel import convert, gauge
#
#def test_convert():
#    fractions = { "1/2": 50, "1/4": 25, "3/4": 75,
#                  "1/3": 33, "2/3": 67, "1/8": 12,
#                  "1/16": 6, "1/32": 3,
#                  "1/0": ZeroDivisionError
#                }
#    for fraction, decimal in fractions.items():
#        assert convert(fraction) == decimal
#
#def test_gauge_empty():
#    test_dict = { 0.0: "E", 0.1: "E", 0.2: "E",
#                  0.3: "E", 0.4: "E", 0.5: "E",
#                  0.6: "E", 0.7: "E", 0.8: "E",
#                  0.9: "E", 1.0: "E"
#                }
#    for fuel, expected in test_dict.items():
#        assert gauge(fuel) == expected
#
#def test_gauge_full():
#    test_dict = { 99.0: "F", 99.1: "F", 99.2: "F",
#                  99.3: "F", 99.4: "F", 99.5: "F",
#                  99.6: "F", 99.7: "F", 99.8: "F",
#                  99.9: "F", 100.0: "F"
#                }
#    for fuel, expected in test_dict.items():
#        assert gauge(fuel) == expected
#
#def test_gauge_percentages():
#    test_dict = { 34: "34%", 56: "56%",
#                  78: "78%", 23: "23%",
#                }
#    for fuel, expected in test_dict.items():
#        assert gauge(fuel) == expected

# Check50 was such a bother for this problem

import pytest
def test_convert():
    assert convert("2/3") == 67
    with pytest.raises(ValueError):
        assert convert("cat/dog")
    with pytest.raises(ValueError):
        assert convert("3/2")
    with pytest.raises(ZeroDivisionError):
        assert convert("0/0")



def test_gauge():
    assert gauge(1) == "E"
    assert gauge(0) == "E"
    assert gauge(99) == "F"
    assert gauge(100) == "F"
    assert gauge(45) == "45%"
