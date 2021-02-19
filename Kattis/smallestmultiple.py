# LCM gcd
# https://open.kattis.com/problems/smallestmultiple
from sys import stdin
from math import gcd

for line in stdin:
    a = list(map(int, line.split()))
    ans = a[0]
    for i in range(1, len(a)):
        ans = ans * a[i] // gcd(ans, a[i])
    print(ans)