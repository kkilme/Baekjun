import math

sosu = []
def prime(n):
    for i in range(2,n) :
        if n % i == 0 :
            break
    else : 
          if n!=1 : sosu.append(n)
         
a = int(input())
b = int(input())
for j in range(a, b+1):
    prime(j)

if sosu == [] : print(-1)
else :
    print(sum(sosu))
    print(min(sosu))