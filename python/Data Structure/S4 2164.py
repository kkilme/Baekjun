# 카드 2
# [맨위 카드 버리기 -> 맨위 카드를 맨 밑으로 보내기] 반복해서 남는 카드
l = [i+1 for i in range(int(input()))]
while len(l) > 1:
    if len(l) % 2 == 0: l = [l[j] for j in range(1, len(l), 2)]
    else:
        tmp = l[-1]
        l = [l[j] for j in range(1, len(l), 2)]
        l.insert(0, tmp)
print(l[0])