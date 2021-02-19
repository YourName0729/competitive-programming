#
# https://open.kattis.com/problems/threepowers
n = 0

while (True):
  n = int(input())
  if n == 0:
    break
  n -= 1

  p = 1
  arr = []
  while (n != 0):
    if n % 2 == 1:
      arr.append(p)
    p *= 3
    n //= 2
  
  print('{ ', end='')
  for i in range(len(arr)):
    print(arr[i], end='')
    if i != len(arr) - 1:
      print(', ', end='')
  print(' }')
