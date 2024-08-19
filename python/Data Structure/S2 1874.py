# 스택 수열
import sys
n = int(input())
l = []
for i in range(n):
    l.append(sys.stdin.readline())
    
prints = []
stack = []
idx = 0
cur = 0

while idx != len(l):
    now = int(l[idx])
    if now <= cur:
        if len(stack) != 0 and stack.pop() == now:
            prints.append('-')
            idx += 1
        else:
            prints = ['NO']
            break
    else:
        while cur != now:
            cur += 1
            stack.append(cur)
            prints.append('+')
    
for w in prints: print(w)