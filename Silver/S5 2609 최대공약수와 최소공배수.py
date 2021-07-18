a,b = map(int, input().split())

def yaksu(a, b):
    while b: a,b = b, a%b   #a에는 b, b에는 a%b를 넣어줌
    print(a)

def baesu(a, b):
    k = min(a, b)
    t = 1
    while(1):
        k = min(a,b)*t
        if k % max(a,b) == 0 :
             print(k)
             break
        else: t+=1

yaksu(a, b)
baesu(a, b)