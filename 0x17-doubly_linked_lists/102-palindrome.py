#!/usr/bin/python3
def is_palindrome(n):
    return str(n) == str(n)[::-1]
def find_largest_palindrome():
    largepal = 0
    for ink in range(100, 1000):
        for jum in range(ink, 1000):
            product = 1 * jum
            if is_palindrome(product) and product > largepal:
                largepal = product
    return largepal
res = find_largest_palindrome()
with open("102-result", "w") as file:
    file.write(str(res))
