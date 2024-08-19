import string

word = input()

alpha = '0' + string.ascii_lowercase + string.ascii_uppercase
n = 0

for k in range(len(word)):
    t = 0
    while word[k] != alpha[t]:
     t += 1
    else:
     n = n+t

for i in range(2, n):
    if n == 1:
         print("It is a prime word.")
    elif n % i == 0:
         print("It is not a prime word.")
         break
else:
    print("It is a prime word.")
