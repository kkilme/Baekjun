from collections import deque

n, w, l = map(int, input().split())
trucks = deque(map(int, input().split()))

onbridge = deque() #deque
trucktimes = deque()

t = 0
 
while trucks or onbridge:
    for i in range(len(trucktimes)):
        trucktimes[i] += 1
    
    if len(trucktimes)!= 0 and trucktimes[0] > w:
        onbridge.popleft()
        trucktimes.popleft()
    if len(trucks) != 0 and sum(onbridge) + trucks[0] <= l:
        onbridge.append(trucks.popleft())
        trucktimes.append(1)
    t+=1

print(t)
