import sys
n = int(input())
l = []
for i in range(n):
    a = int(sys.stdin.readline().rstrip())
    if a == 0 : del l[len(l)-1]
    else : l.append(a)

print(sum(l))