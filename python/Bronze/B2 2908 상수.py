a,b = map(str, input().split())
na = int(a[::-1])
nb = int(b[::-1])
print(max(na, nb))