# 2024-09-14 피보나치 수

n = int(input())

l = [1, 1]

for i in range(2, n):
    l.append(l[i-1] + l[i-2])
    
print(l[n-1])