from bank import value

def test_value():
    assert value("Hello") == 0
    assert value("How do you do?") == 20
    assert value("What is your name?") == 100
    print("All tests pass")
