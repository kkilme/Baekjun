a,b,c,d = map(int, input().split())

e = min(c-a, a)
f = min(d-b, b)
print(min(e,f))