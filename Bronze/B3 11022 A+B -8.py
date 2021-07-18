a = 1
for k in range(int(input())):
    b,c = map(int, input().split())
    k = b+c
    print(f'Case #{a}:',b,'+',c,'=',k)
    a=a+1