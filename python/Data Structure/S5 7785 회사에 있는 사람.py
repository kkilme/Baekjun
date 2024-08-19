import sys
n = int(input())
now = dict()
for i in range(n):
    a = list(sys.stdin.readline().split())
    if a[1] == 'enter' : now[a[0]] = 1
    else : del now[a[0]]

now = sorted(now.keys(), reverse=True)
for j in now:
    print(j)