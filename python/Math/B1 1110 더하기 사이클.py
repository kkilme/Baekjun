a = input()

if int(a)<10 : a = '0' + a

n = a
t = 0

while(1):
     k = str(int(n[0]) + int(n[1]))
     if int(k) < 10 : k = '0' + k
     n = (n[1]+k[1])  
    
     if n == a :
         print(t+1)
         break
     else : t+=1