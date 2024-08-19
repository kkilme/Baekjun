n, m = map(int, input().split())
arr = list()
for i in range(n):
    arr.append(i+1)
for _ in range(m):
    a, b = map(int, input().split())
    arr[a-1], arr[b-1] = arr[b-1], arr[a-1]
print(*arr)
