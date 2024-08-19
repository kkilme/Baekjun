# 덩치
# x,y 둘 다 커야 덩치가 더 큼. 덩치 순위 정하기

data = []
n = int(input())
ans = [0] * n
for _ in range(n):
    a, b = map(int, input().split())
    data.append((a,b))
i = 0
for a, b in data:
    k = 1
    for c, d in data:
        if a < c and b < d: k+=1
    ans[i] = k
    i += 1

print(' '.join(map(str, ans)))