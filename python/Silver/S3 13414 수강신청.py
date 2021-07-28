import sys
maxn, S_n = map(int, input().split())
Sdict = {}
for i in range(S_n):
    Sdict.update({sys.stdin.readline().rstrip():i})

S_S = sorted(Sdict.items(), key= lambda x : x[1])

if len(S_S) < maxn :
    for j in range(len(S_S)):
        print(S_S[j][0])
else :
    for j in range(maxn):
        print(S_S[j][0])