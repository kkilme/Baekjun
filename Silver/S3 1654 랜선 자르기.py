import sys

k, n = map(int, input().split())

arr = []
for _ in range(k):
    arr.append(int(sys.stdin.readline()))

high = max(arr)
low = 1

# 시간초과
# sum = 0

# for i in range(n, 1, -1):
#     for j in arr:
#         sum += j//(m//i)
    
#     if sum < n :
#         if i == 1 : print(m)
#         else : 
#            print(m//(i+1))
#            break
#     else : sum = 0

# 이분탐색
while low <= high:
    mid = (low+high)//2
    sum = 0

    for i in arr:
        sum += i//mid
    
    if sum < n : high = mid - 1
    else : low = mid + 1

print(high)