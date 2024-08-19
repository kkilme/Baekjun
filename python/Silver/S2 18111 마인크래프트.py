import sys

n, m, b = map(int, sys.stdin.readline().split())

l = dict()
sum = 0
time = 1000000000000000000000000000000

for _ in range(n):
    k = list(map(int, sys.stdin.readline().split()))
    for s in k:
        if s in l : l[s]+=1 
        else : l.update({s:1})

for j in l.keys():
    sum += j*l[j]

for i in range(257):
    
    t = 0
    output = 0
    inp = 0

    if sum + b >= i * n * m:
        
        for k in l.keys():
            if i > k :
                t += (i - k) * l[k]
            elif i < k : 
                t += (k - i) * 2 * l[k]

        if time >= t : 
            time = t
            h = i

print(time, h)