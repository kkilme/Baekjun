k = int(input())
r = []
for _ in range(k):
    a, b = input().split()
    n = int(a)
    t = ''
    for i in range(len(b)):
            t += str(b[i]*n)
            
    r.append(t)

for i in range(len(r)):
    print(r[i])