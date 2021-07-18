T = int(input())
for i in range(T):
    h, w, n = map(int, input().split())
    f = n%h
    if f == 0 : f = h
    if n <= h  : r = 1
    elif n%h == 0 : r = n//h
    else : r = (n//h)+1
    if r<10 : r = '0'+str(r)
    print(f"{f}{r}")