n = int(input())
for i in range(n):
    print(' '*(n-i-1) , end='')
    print('*'*i,end='')
    print('*',end='')
    print('*'*i)

for i in reversed(range(n-1)):
    print(' '*(n-i-1) , end='')
    print('*'*i,end='')
    print('*',end='')
    print('*'*i)
