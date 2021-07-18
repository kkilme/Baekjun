import sys
n = int(input())
l = list(map(int, sys.stdin.readline().split()))
sum = 0
ln = int(len(l))
l.sort(reverse=True)
for i in range(ln):
    sum += (2*ln-2-4*i)*l[i]

print(sum)