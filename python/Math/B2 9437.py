# 2025-08-15 사라진 페이지 찾기
while(True):
    line = input()
    if line == "0":
        break
    n, p = map(int, line.split())
    i = p
    answer = []
    
    if p % 2 == 0:
        i-=1
        answer.append(p-1)
    else: answer.append(p+1)
    
    i = n - i
    answer.append(i)
    answer.append(i+1)
    
    answer.sort()
    print(" ".join(map(str, answer)))
        