a, b = map(int, input().split())

l = list(i+1 for i in range(a))
arr = []

delnum = b-1
while len(l):
    if delnum >= len(l):
        delnum = delnum % len(l)
    else :
        arr.append(str(l.pop(delnum)))
        delnum += b-1

print('<',", ".join(arr),">", sep='')