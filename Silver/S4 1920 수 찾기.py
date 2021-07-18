import sys

n = int(input())
k = list(map(int, sys.stdin.readline().split()))


nums = {}
for i in k:
    if i not in nums : nums.update({i:1})

m = int(input())
t = list(map(int, sys.stdin.readline().split()))
for j in t:
    if j in nums : print(1)
    else : print(0)