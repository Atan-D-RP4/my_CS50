import pytest
from working import convert

#def test_convert():
#    test_dict = { "9:00 AM to 5:00 PM" : "09:00 to 17:00",
#                  "12:00 PM to 3:00 PM": "12:00 to 15:00",
#                  "12:00 AM to 3:00 AM": "00:00 to 03:00",
#                  "12:00 PM to 3:00 AM": "12:00 to 03:00",
#                  "9:70 AM to 5:00 PM" : None,
#                  "9:00 AM to 5:70 PM" : None,
#                  "9:00 to 17:00"      : None,
#                  "9:00 AM - 5:00 PM"  : None,
#                  "10:7 AM - 5:1 PM"   : None,
#                  "9-00 AM to 5-00 PM" : None
#                }
#    for key, value in test_dict.items():
#        assert convert(key) == value
#
#def test_time_with_minutes():
#    assert convert("10:30 PM to 8:50 AM") == "22:30 to 08:50"
#
#def test_time_without_minutes():
#    assert convert("10 PM to 8 AM") == "22:00 to 08:00"
#
#def test_wrong_minutes():
#    with pytest.raises(ValueError):
#        assert convert("10:70 PM to 8:50 AM") == None
#    with pytest.raises(ValueError):
#        assert convert("10:30 PM to 8:70 AM") == None
#
#def test_wrong_hours():
#    with pytest.raises(ValueError):
#        assert convert("10:30 PM to 28:50 AM") == None
#    with pytest.raises(ValueError):
#        assert convert("30:30 PM to 8:50 AM") == None
#
#def test_without_to():
#    with pytest.raises(ValueError):
#        assert convert("10:30 PM 8:50 AM") == None
#    with pytest.raises(ValueError):
#        assert convert("10:30 PM 8:50 AM") == None
#
#def test_invalid_format():
#    with pytest.raises(ValueError):
#        assert convert("10:30 PM - 8:50 AM") == None
#    with pytest.raises(ValueError):
#        assert convert("9-00 AM to 5-00 PM") == None
#    with pytest.raises(ValueError):
#        assert convert("10:30 PM, 8:50 AM") == None
#
#
def test_convert():
    assert convert("9 AM to 5 PM") == "09:00 to 17:00"
    assert convert("9:00 AM to 5:00 PM") == "09:00 to 17:00"
    assert convert("10 PM to 8 AM") == "22:00 to 08:00"
    assert convert("10:30 PM to 8:50 AM") == "22:30 to 08:50"

def test_value_error():
    with pytest.raises(ValueError):
        convert("9AM - 5PM")
    with pytest.raises(ValueError):
        convert("09:00 to 17:00")
    with pytest.raises(ValueError):
        convert("15:00 AM to 25:00 PM")
    with pytest.raises(ValueError):
        convert("9:60 AM to 5:60 PM")

# The tests just aren't passing check50.
# Even though all the tests are passing with pytest, I still get this:
# :( correct working.py passes all test_working checks
#     expected exit code 0, not 2
# :| test_working.py catches working.py printing hours off by one
#     can't check until a frown turns upside down
# :| test_working.py catches working.py printing minutes off by five
#     can't check until a frown turns upside down
# :| test_working.py catches working.py not raising ValueError when user omits " to "
#     can't check until a frown turns upside down
# :| test_working.py catches working.py not raising ValueError for out-of-range times
#     can't check until a frown turns upside down

# So whatever

