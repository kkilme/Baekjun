a, b = map(int, input().split())
c = max(a, b)
d = min(a, b)
print(((c-d+1)*(c+d))//2)