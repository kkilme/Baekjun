a = (sum(map(int, input().split())))
b = (sum(map(int, input().split())))
c = (sum(map(int, input().split())))

k = [a, b, c]
for s in k:
    if s == 4 : print('E')
    elif s == 3 : print('A')
    elif s == 2 : print('B')
    elif s == 1 : print('C')
    elif s == 0 : print('D')