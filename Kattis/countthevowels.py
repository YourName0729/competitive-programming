# https://open.kattis.com/problems/countthevowels
s = input()
print(sum([s.count(c) for c in 'aeiouAEIOU']))