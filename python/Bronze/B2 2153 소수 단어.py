word = input()

alpha = ['null','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
         'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
n = 0

for k in range(len(word)):
    t=0
    while word[k] != alpha[t] :
        t+=1
    else : 
     n = n+t

for i in range(2,n) :
     if n == 1 : print("It is a prime word.")
     elif n % i == 0 :
         print("It is not a prime word.")
         break
else : print("It is a prime word.")
