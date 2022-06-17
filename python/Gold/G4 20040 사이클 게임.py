import sys

n, m = map(int,input().split())

answer = 0
tree = [i for i in range(n)]

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

def union(a, b, arr):
    ap = find(a, arr)
    bp = find(b, arr)
    if ap != bp:
        arr[ap] = bp

for i in range(m):
    l, k = map(int,sys.stdin.readline().split())
    lp = find(l, tree)
    kp = find(k, tree)
    if lp == kp: 
        answer = i +1
        break
    tree[lp] = kp

print(answer)