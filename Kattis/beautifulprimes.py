# number_theory
# https://open.kattis.com/problems/beautifulprimes
from sys import stdin

T = int(input())
for i in range(T):
    n = int(input())
    s, d = 1, 1
    for j in range(n):
        if s * 7 >= d:
            print(7, end=' ')
            s *= 7
        else:
            print(11, end=' ')
            s *= 11
        d *= 10
    print()