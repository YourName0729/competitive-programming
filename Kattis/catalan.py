# discrete_mathematics
# https://open.kattis.com/problems/catalan
ans = [1]
for i in range(5001):
    ans.append(ans[-1] * (4 * i + 2) // (i + 2))
for i in range(int(input())):
    print(ans[int(input())])