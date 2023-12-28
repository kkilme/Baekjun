# 블랙잭
# m보다 크지 않으면서 가장 가까운 3개의 합

n, m = map(int,input().split())
l = list(map(int, input().split()))
ans = 0
for i in range(len(l)-2):
    a = l[i]
    for p in range(i+1, len(l)-1):
        b = l[p]
        for j in range(p+1, len(l)):
            k = a + b + l[j]
            if k > ans and k <= m:
                ans = k
    if ans == m: break

print(ans)