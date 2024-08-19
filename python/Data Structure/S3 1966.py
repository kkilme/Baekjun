# 프린터 큐
# 우선순위큐에서 특정 요소의 출력 순서 구하기
# 중요도가 같을 수 있음

for _ in range(int(input())):
    n, k = map(int,input().split())
    queue = list(enumerate(map(int, input().split())))
    ans = 0
    while queue:
        mx = max(tup[1] for tup in queue)
        idx, now = queue.pop(0)
        if now == mx:
            ans += 1
            if k == idx: break
        else: queue.append((idx, now))

    print(ans)