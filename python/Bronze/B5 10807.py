n = input()
arr = list(map(int, input().split()))
k = int(input())
count = 0
for i in arr:
    if i==k: count+=1
print(count)