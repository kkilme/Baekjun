n = int(input())
s1 = list(map(int, input().split()))
s2 = []
answer = []

target = n
while target!=0:
    if target in s1:
        while s1[len(s1)-1] != target:
            s2.append(s1.pop())
            answer.append("1 2")
        s1.pop()
        answer.append("1 3")
    else:
        while s2[len(s2)-1] != target:
            s1.append(s2.pop())
            answer.append("2 1")
        s2.pop()
        answer.append("2 3")
    target -=1

print(len(answer))
for a in answer:
    print(a)