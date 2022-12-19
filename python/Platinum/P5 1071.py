n = int(input())
ns = list(map(int, input().split()))
ns.sort()
sni = 0 # same number index
for i in range(len(ns)-1):
    if ns[i] != ns[sni]: sni = i
    if ns[i] + 1 == ns[i+1]:
        si = 0 # swap index
        for j in range(i+1, len(ns)):
            if ns[j] != ns[i+1]:
                si = j
                break
        if not si: 
            si = sni
            sni +=1
        ns[i+1], ns[si] = ns[si], ns[i+1]
print(*ns)