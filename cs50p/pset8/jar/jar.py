class Jar:
    def __init__(self, capacity=12):
        if capacity < 0:
            raise ValueError("Capacity must be a non-negative integer")
        self._capacity = capacity  # Using a different attribute name to avoid conflict
        self._count = 0

    def __str__(self):
        cookies = ["🍪" for _ in range(self._count)]  # Using a better cookie representation
        return "".join(cookies)

    def deposit(self, n):
        if n < 0:
            raise ValueError("Cannot deposit a negative number of cookies")
        if self._count + n > self._capacity:
            raise ValueError("Too many cookies in the jar")
        self._count += n

    def withdraw(self, n):
        if n < 0:
            raise ValueError("Cannot withdraw a negative number of cookies")
        if n > self._count:
            raise ValueError("Not enough cookies in the jar")
        self._count -= n

    @property
    def capacity(self):
        return self._capacity  # Return the internal capacity attribute

    @property
    def size(self):
        return self._count  # Return the internal count attribute
