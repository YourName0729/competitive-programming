# https://open.kattis.com/problems/modulararithmetic
from sys import stdin
import math

def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('modular inverse does not exist')
    else:
        return x % m

while 1:
    n, t = list(map(int, input().split()))
    if n == 0:
        break
    for i in range(t):
        s = input().split()
        x, y, op = int(s[0]), int(s[2]), s[1]
        if op == '+':
            print((x + y) % n)
        elif op == '-':
            print((x - y + n) % n)
        elif op == '*':
            print((x * y) % n)
        else:
            if math.gcd(y, n) != 1:
                print(-1)
            else:
                print((x * modinv(y, n)) % n)
