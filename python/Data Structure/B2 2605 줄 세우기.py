n = int(input())
l = list(map(int,input().split()))
line = list()
for i in range(n):
    line.insert(i-l[i],i+1)

for s in line:
    print(s, end=' ')