import sys
n = int(input())
l = []
for _ in range(n):
    k = list(map(int, sys.stdin.readline().split()))
    l.extend([k])

l.sort(key=lambda x : (x[1],x[0]))


for i in range(n):
    print(l[i][0],l[i][1])