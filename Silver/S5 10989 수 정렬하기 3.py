import sys

n = int(input())

arr = [0 for _ in range(10000)]

for _ in range(n):
    num = int(sys.stdin.readline().rstrip())
    arr[num-1] += 1

for i in range(1, 10001):
    for j in range(arr[i-1]):
        print(i)
        
