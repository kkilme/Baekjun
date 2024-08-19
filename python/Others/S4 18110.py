# solved.ac
# 30% 절사평균 구하기
# 파이썬 round: 오사오입, 사사오입 반올림을 위해 메소드 새로 만듦
import sys
def round2(n):
    k = int(n)
    return k + 1 if n - k >= 0.5 else k
n = int(input())
data = []
for i in range(n):
    data.append(int(sys.stdin.readline()))
data.sort()
dead = int(round2(len(data) * 0.15))
if dead != 0: data = data[dead : -dead]
if n == 0: print(0)
else: print(int(round2(sum(data)/len(data))))