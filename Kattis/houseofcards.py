# number_theory
# https://open.kattis.com/problems/houseofcards
from sys import stdin

n = int(input())
while 1:
    a, b = 3 * n + 1, n
    if (a % 8 == 0) or (a % 4 == 0 and b % 2 == 0) or (a % 2 == 0 and b % 4 == 0) or (b % 8 == 0):
        print(n)
        break
    n += 1
