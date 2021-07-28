import sys
n = int(input())
nums = []
for _ in range(n): nums.append(int(sys.stdin.readline().rstrip()))
nums.sort()
for i in range(n): 
     print(nums[i])