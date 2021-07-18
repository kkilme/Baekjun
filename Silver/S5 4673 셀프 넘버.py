T = [True]*10001
for i in range(1, 10000):
    if T[i]:
        nn = i
        print(i)
        while(1):
         t = nn
         k = len(str(nn))
         for j in range(k):
             nn += int(str(t)[j])
        
         if nn>10000 : break
         T[nn] = False