import sys
import heapq #minheap -> minNode 구현

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

dist = list() # 거리 저장할 리스트
for _ in range(n+1):
    dist.append(1000000) #초기값 100만(문제에서 최대 비용이 10만)

graph = [[] for _ in range(n+1)] #index 0은 사용 안하기때문에 n+1크기로 해줌..(도시번호가 1번부터 시작)

for _ in range(m):
    s, d, w = map(int, sys.stdin.readline().split())
    graph[s].append((d,w)) #그래프 완성! s:시작도시 d: 도착도시, w:버스비용


def dijkstra(start):
    s = [(0,start)] #현재 가능한 이웃의 (비용, 정점)을 모으는 minheap으로 사용 -> 가장 낮은 비용을 가지는 이웃을 꺼낼 수 있음
    dist[start] = 0 #시작지점은 거리 0
    while len(s)!=0: #더 갈수 있는 이웃이 없으면 종료
        wnow, v = heapq.heappop(s) #s에서 비용이 가장 낮은것을 pop

        if dist[v] < wnow: continue #이미 최소거리인 경우 continue

        for n in graph[v]: # 도시번호가 v인 곳에서 시작하는 모든 버스 n에 대해서..

            d = n[0] # 해당버스의 도착지
            wdes = n[1] # 해당버스의 비용
            
            if dist[d] > wnow + wdes: # 거리에 저장된 값을 최솟값으로 갱신..
                dist[d] = wnow + wdes
                heapq.heappush(s, (dist[d], d)) #도착지까지 가는 비용과 도착지를 s에 다시 넣어줌.. 새로운 neighbor

start, destination = map(int,sys.stdin.readline().split())
dijkstra(start)
# print(dist)
print(dist[destination]) #도착지점까지의 최소거리 출력