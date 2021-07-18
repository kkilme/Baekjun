import sys

k, n = map(int, input().split())

arr = []
for _ in range(k):
    arr.append(int(sys.stdin.readline()))

print(arr)