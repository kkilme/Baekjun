n = int(input())
cnt = 0 
for i in range(1,n+1):
    if i<100 : cnt += 1
    else : 
        j = str(i)
        a = int(j[0])
        b = int(j[1])
        c = int(j[2])
        if c-b == b-a : cnt +=1
    
print(cnt)