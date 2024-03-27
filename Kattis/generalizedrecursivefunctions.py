
t = int(input())

for tc in range(t):
    lst = list(map(int, input().split()))
    a = lst[:-2:2]
    b = lst[1:-1:2]
    c = lst[-2]
    d = lst[-1]
    
    mp = dict()
    def f(x, y) -> int:
        v = mp.get((x, y), -1)
        if v != -1:
            return v

        if x <= 0 or y <= 0:
            return d
        
        sm = c
        for i in range(len(a)):
            sm += f(x - a[i], y - b[i])
        mp[(x, y)] = sm
        return sm
    
    lst = list(map(int, input().split()))
    xs = lst[::2]
    ys = lst[1::2]
    for i in range(len(xs)):
        print(f(xs[i], ys[i]))
    print("")