import sys

n = int(input())
user = []
for j in range(n):
    a = sys.stdin.readline().split()
    user.append(a)

user.sort(key= lambda x : int(x[0]))

for i in user: print(i[0],i[1])