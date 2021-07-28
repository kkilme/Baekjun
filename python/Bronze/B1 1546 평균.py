n = int(input())
score = list(map(int, input().split()))
m = max(score)
total = 0

for i in range(n):
    score[i] = (score[i]/m)*100


for k in range(n):
    total += score[k]


print(total/n)