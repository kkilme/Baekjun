import sys
n = int(input()) #케이스 개수
for i in range(n):
    l = list(map(int, sys.stdin.readline().split())) 
    s_n = l[0] #학생수
    del l[0] #학생수 리스트에서 삭제
    avr = sum(l)/s_n #평균
    new_l = []
    for j in l:
        if j > avr:
            new_l.append(j) #평균이상인 학생
    per = (len(new_l)/s_n)*100 #퍼센트
    print('{:.3f}%'.format(per))

