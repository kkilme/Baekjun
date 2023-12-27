# 팩토리얼 0의 개수
# N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수
n = int(input())
k = 1
ans = 0
for i in range(n):
    k *= i+1
    while k % 10 == 0:
        ans +=1
        k //= 10
print(ans)