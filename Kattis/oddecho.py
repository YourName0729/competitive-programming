# https://open.kattis.com/problems/oddecho
n = int(input())
for i in range(n):
    s = input()
    if i % 2 == 0:
        print(s)