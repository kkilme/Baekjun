import math

a, b = map(int, input().split())
def prime(n):
    
    if n > 100:
        for i in range(2,math.ceil((math.sqrt(n)))+1) :
             if n % i == 0 :
                 break
        else : 
             if n!=1 : 
                 print(n)
                   
    else : 
        for i in range(2,n) :
             if n % i == 0 :
                 break
        else : 
             if n!=1 : 
                 print(n)
                 

for j in range(a, b+1):
    prime(j)