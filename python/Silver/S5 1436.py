n = int(input())

idx = 0
for i in range(10000000):
    if str(i).find('666') != -1:
        idx+=1
    if(idx == n):
        print(i)
        break