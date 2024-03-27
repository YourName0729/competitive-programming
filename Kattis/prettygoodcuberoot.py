from sys import stdin


for line in stdin:
    n = int(line)
    l, r = 0, n
    while l + 10 < r:
        mid = (l + r) // 2
        if mid * mid * mid < n:
            l = mid
        elif mid * mid * mid > n:
            r = mid
        else:
            l, r = mid, mid

    ansl = l
    ansd = n
    for i in range(l, r + 1):
        d = abs(i * i * i - n)
        if d < ansd:
            ansl, ansd = i, d

    print(ansl)