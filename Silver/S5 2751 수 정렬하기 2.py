import sys
n = int(input())
t = []
for _ in range(n):
    t.append(int(sys.stdin.readline()))

t.sort()

for i in t:
    print(i)