# greedy
# https://open.kattis.com/problems/persistent
from sys import stdin
from math import gcd

for line in stdin:
    d = int(line)
    if d == -1:
        break
    if d == 0:
        print(10)
    elif d < 10:
        print(10 + d)
    else:
        a = []
        for i in range(2, 10):
            a.append(0)
            while d % (11 - i) == 0:
                a[-1] += 1
                d = d // (11 - i)
        if d != 1:
            print('There is no such number.')
        else:
            for i in range(len(a)):
                for j in range(a[-(i+1)]):
                    print(i + 2, end = '')
            print('')