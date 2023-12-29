# 유기농 배추
# 2차원 배열에서 영역 수 구하기 (dfs bfs)
direction = [(-1, 0), (0, -1), (1, 0), (0, 1)]
for _ in range(int(input())):
    m, n, k = map(int, input().split())
    graph = [[0 for _ in range(m+2)] for _ in range(n+2)]
    check = [[-1 for _ in range(m+2)] for _ in range(n+2)]
    for i in range(k):
        x, y = map(int, input().split())
        graph[y+1][x+1] = 1
    ans = 0
    for i in range(1, n+1):
        for j in range(1, m+1):
            if graph[i][j] == 1 and check[i][j] == -1:
                ans += 1
                check[i][j] = 1
                stack = [(i, j)]
                while stack:
                    a, b = stack.pop()
                    for X, Y in direction:
                        y, x = a + Y, b + X
                        if graph[y][x] == 1 and check[y][x] == -1:
                            check[y][x] = 1
                            stack.append((y, x))
    print(ans)