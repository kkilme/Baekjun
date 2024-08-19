import queue


n = int(input())

presents = queue.PriorityQueue() #우선순위 큐

for _ in range(n):
    a = list(map(int,input().split()))
    if len(a) == 1:
        if presents._qsize() != 0: print(-presents.get())
        else: print(-1)
    else:
        a.pop(0)
        for p in a:
            presents.put(-p)