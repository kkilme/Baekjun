# 통계학
# 산술평균, 중앙값, 최빈값, 범위 구하기
import sys
n = int(input())
data = []
count = {}
for i in range(n):
    k = int(sys.stdin.readline())
    count[k] = count.get(k, 0) + 1
    data.append(k)
data.sort()
print(int(round(sum(data) / len(data),0)))
print(data[len(data)//2])
mx = count[max(count, key=count.get)]
maxkeys = []
for k, v in count.items():
    if v == mx: maxkeys.append(k)
maxkeys.sort()
print(maxkeys[1] if len(maxkeys) > 1 else maxkeys[0])
print(max(data) - min(data))