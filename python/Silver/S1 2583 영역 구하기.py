from collections import deque

m, n, k = map(int, input().split())
paper = list()
directions = [[0,1],[-1,0],[0,-1],[1,0]]
for i in range(m):
    paper.append([])
    for _ in range(n):
        paper[i].append(0)

for _ in range(k):
    x1, y1, x2, y2 = map(int, input().split())
    for i in range(y1,y2):
        for j in range(x1,x2):
            paper[i][j] = 1

def dfs(x, y, paper):
    count = 1
    s = deque() # stack으로 사용
    s.append([y,x])
    while len(s) != 0:
        v = s.pop()
        paper[v[0]][v[1]] = 1
        for d in directions:
            xx = v[1] + d[0]
            yy = v[0] + d[1]
            if xx < 0 or xx >= n or yy < 0 or yy >= m: continue
            if paper[yy][xx] != 1:
                if [yy,xx] in s: continue
                s.append([yy,xx])
                count+=1
    return count

area = list()
areacount = 0

for i in range(m):
    for j in range(n):
        if paper[i][j] == 1: continue
        if paper[i][j] == 0:
            c = dfs(j, i, paper)
            area.append(c)
        areacount += 1

print(areacount)
area.sort()
for i in area:
    print(i, end=' ')