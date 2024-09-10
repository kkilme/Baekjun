h, w = map(int, input().split())
S = h*w
a = list(map(int, input().split()))
for i in range(5):
    print(a[i]-S, end=' ')