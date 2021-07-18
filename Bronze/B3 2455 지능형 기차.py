x, a = map(int, input().split())
b, c = map(int, input().split())
d, e = map(int, input().split())
f, x = map(int, input().split())

t = [a, a-b+c, a-b+c-d+e]
print(max(t))