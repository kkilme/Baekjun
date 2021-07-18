a, b = map(int, input().split())
no_listen = {'0'}
no_see = {'0'}
for _ in range(a):
    no_listen.add(input())

for _ in range(b):
    no_see.add(input())

no_sl = sorted(list(no_see&no_listen))
no_sl.remove('0')

print(len(no_sl))
for i in range(len(no_sl)):
    print(no_sl[i])