import sys

n, m, b = map(int, sys.stdin.readline().split())


l = []

time = 1000000000000000000000000000000

for _ in range(n):
    k = list(map(int, sys.stdin.readline().split()))
    for i in k:
        l.append(i)

sum = sum(l)

for i in range(257):
    
    output = 0
    inp = 0

    if sum + b >= i * n * m:
        for j in l:
            if i > j :
                output += i - j
            elif i < j : 
                inp += j - i

        if output > inp + b : continue
        else :
            t = inp*2 + output
            
            if time >= t : 
                time = t
                h = i

print(time, h)