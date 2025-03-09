from jar import Jar
import pytest

def test_jar_init():
    jar = Jar()
    assert jar._capacity == 12
    assert jar._count == 0

def test_jar_deposit():
    jar = Jar(5)
    assert jar._count == 0
    jar.deposit(2)
    assert jar._count == 2
    jar.deposit(3)
    assert jar._count == 5
    with pytest.raises(ValueError):
        jar.deposit(1)


def test_jar_str():
    jar5 = Jar(5)
    assert jar5._count == 0
    jar5.deposit(5)
    assert str(jar5) == "🍪🍪🍪🍪🍪"
    jar2 = Jar(2)
    assert jar2._count == 0
    jar2.deposit(2)
    assert str(jar2) == "🍪🍪"
    jar0 = Jar(0)
    assert str(jar0) == ""

def test_jar_withdraw():
    jar = Jar(5)
    jar.deposit(5)
    assert jar._count == 5
    jar.withdraw(2)
    assert jar._count == 3
    jar.withdraw(3)
    assert jar._count == 0
    with pytest.raises(ValueError):
        jar.withdraw(1)

def test_jar__capacity():
    jar = Jar(5)
    assert jar.capacity == jar._capacity

def test_jar_size():
    jar = Jar(5)
    assert jar.size == 0
    jar.deposit(2)
    assert jar.size == jar._count
    jar.withdraw(1)
    assert jar.size == jar._count
