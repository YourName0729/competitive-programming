#
# https://open.kattis.com/problems/thedealoftheday
ans = 0
k = 0
arr = [0 for i in range(10)]
sv = [0 for i in range(10)]

def go(cur, at):
  global ans
  sv[at] = cur
  if at == k - 1:


    tmp = 1
    for i in range(k):
      tmp *= arr[sv[i]]
    ans += tmp
    return

  for i in range(cur + 1, 10):
    go(i, at + 1)

arr = [int(x) for x in input().split()]
k = int(input())

for i in range(10):
  go(i, 0)

print(ans)