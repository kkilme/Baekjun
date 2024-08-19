import sys

n = int(input())

for _ in range(n):
    print(sum(list(map(int, sys.stdin.readline().split()))))