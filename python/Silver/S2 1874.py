n = int(input())
l = []
for i in range(n):
    l.append(input())
printl = []
idx = 0
cur = 1
count = 0
increasing = False
while idx != len(l):
    if l[idx] >= cur and not increasing:
        increasing = True
        printl.append(['+', l[idx] - cur + 1])
        printl.append(['-', 1])
        cur = l[idx]
        idx+=1
    elif l[idx] < cur:
        increasing = False


print('end')