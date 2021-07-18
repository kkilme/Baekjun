a,b = map(int, input().split())
c = list(map(int, input().split()))

for k in range(a) :
    if min(b,c[k]) == c[k] and b != c[k]: print(c[k], end=' ')
    else : continue