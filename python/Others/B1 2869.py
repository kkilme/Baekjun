# 달팽이는 올라가고 싶다
# 하루에 a 상승, b 하락, 총 길이 v, 걸리는 날 수?

a, b, v = map(int, input().split())
d = (v-a) // (a-b)
left = (v-a) % (a-b)
print(d + 1 if left == 0 else d + 2)