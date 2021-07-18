a = int(input()) 
k = 6
n = 1
i = 2
if a == 1 : print("1")
elif 1 < a < 8 : print("2")
else : 
    while 1:
       if n < a <= n+k :
           print(i)
           break
       else :
           n = n+k
           k+=6
           i+=1