n = list(map(int, input().split()))
h = min(n)
n = sorted(n, reverse=True)
w = n[1]
print(w*h)