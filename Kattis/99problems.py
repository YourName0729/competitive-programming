# https://open.kattis.com/problems/99problems
a = int(input())
x = a // 100 * 100 + 99
y = a // 100 * 100 - 1
if x - a <= a - y or y < 0:
    print(x)
else:
    print(y)