n = int(input())

l = 1
a = [1, 2, 3, 4, 5, 6, 7, 8, 9]

for i in range(n - 1):
    l += 1
    b = []
    for x in a:
        for j in range(10):
            v = x * 10 + j
            if v % l == 0:
                b.append(v)
    a = b
    # print(a)

print(len(a))