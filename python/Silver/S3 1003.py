# 피보나치 함수
# 각 피보나치 수의 fibo(0), fibo(1) 호출 횟수 구하기

memo = [(1, 0), (0, 1)]
for i in range(40):
    memo.append((memo[i][0] + memo[i+1][0], memo[i][1] + memo[i+1][1]))
for _ in range(int(input())):
    n = int(input())
    a, b = memo[n]
    print(a, b)