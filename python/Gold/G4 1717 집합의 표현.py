import sys

def union(a, b, arr):
    ap = find(a, arr)
    bp = find(b, arr)
    if ap != bp:
        arr[ap] = bp

def find(a, arr):
    r = arr[a] # r: root
    while r!= arr[r]: r = arr[r] # root 찾기

    # path compression
    c = a
    while c!= arr[c]:
        cp = arr[c]
        arr[c] = r # root로 연결
        c = cp
    return r

n,m = map(int, input().split())

arr = list()
for i in range(n+1):
    arr.append(i)

for _ in range(m):
    k, a, b = map(int, sys.stdin.readline().split())
    if k == 0:
        union(a, b, arr)
    else:
        ap = find(a, arr)
        bp = find(b, arr)
        if ap == bp: print("YES")
        else: print("NO")

