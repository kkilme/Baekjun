import sys

n = int(input())

def find(a, net):
    r = net[a] # r: root
    while r!= net[r]: r = net[r] # root 찾기

    # path compression
    c = a
    while c!= net[c]:
        cp = net[c]
        net[c] = r # root로 연결
        c = cp
    return r

def union(a, b, net, friends):
    ar = find(a, net)
    br = find(b, net)

    if ar!=br:
        net[br] = ar
        friends[ar] += friends[br]

for _ in range(n):
    m = int(input())
    network = dict() # 실제 친구 관계
    friends = dict() # 친구 관계 내의 인원수 셈
    for _ in range(m):
        count = 0
        l, k = sys.stdin.readline().split()
        if l not in network.keys():
            network[l] = l
            friends[l] = 1
        if k not in network.keys():
            network[k] = k
            friends[k] = 1
            
        union(l, k, network, friends)

        lr = find(l, network)
        print(friends[lr])

