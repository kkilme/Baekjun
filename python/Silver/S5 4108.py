def countmine(j, k):
    count = 0
    for di in direction:
        if j+di[0] <0 or k+di[1] <0 or j+di[0] >= R or k+di[1] >= C: continue
        if prob[j+di[0]][k+di[1]] == '*':
            count += 1

    return count

while True:
    R, C = map(int, input().split())
    if R == 0 and C == 0: break
    prob = []
    answer = []
    direction = [[0, 1], [1, 1], [1, 0], [0, -1], [1, -1], [-1, -1], [-1, 0], [-1,1]]
    for i in range(R):
        prob.append(input())
        answer.append([])
    for j in range(R):
        for k in range(C):
            if prob[j][k] == '.':
                answer[j].append(countmine(j, k))
            else:
                answer[j].append('*')

    for j in range(R):
        for k in range(C):
            print(answer[j][k], end='')
        print()