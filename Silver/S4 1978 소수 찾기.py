n = int(input())

k = list(map(int, input().split()))
cnt = 0
def prime(n):
    global cnt
    for i in range(2,n) :
        if n % i == 0 :
            break
    else : 
          if n!=1 : cnt+=1


for i in k:
    prime(i)

print(cnt)