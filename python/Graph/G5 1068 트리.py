n = int(input())
tree = list(map(int, input().split()))
delnode = int(input())
willdelete = list()
notleaf = set()
def deln(a, arr, delnode):
    r = arr[a] # r: root
    if r == -1:
        return
    if r == delnode:
        willdelete.append(a)
        return
    while r!= -1:
        r = arr[r] # root 찾기
        if r == delnode:
            willdelete.append(a)
            break
    
def findnotleaf(a, arr):
    r = arr[a]
    if r == -1:
        return
    if r == -2:
        notleaf.add(a)
        return
    notleaf.add(r)

for i in range(len(tree)):
    deln(i, tree, delnode)
tree[delnode] = -2
for n in willdelete:
    tree[n] = -2

for i in range(len(tree)):
    findnotleaf(i, tree)
print(len(tree) - len(notleaf))