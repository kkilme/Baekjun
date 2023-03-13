n, m = map(int, input().split())
arr = list()
for i in range(n):
    arr.append(i+1)
for _ in range(m):
    a, b = map(int, input().split())
    for i in range((b-a+1)//2):
        arr[a-1+i], arr[b-1-i] = arr[b-1-i], arr[a-1+i]
print(*arr)