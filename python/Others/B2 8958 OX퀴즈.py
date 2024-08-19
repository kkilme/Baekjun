n = int(input())
#a = []
for _ in range(n):
    t=0
    k=0
    result = list(str(input()))
    for i in range(len(result)):
        if result[i] == 'O':
             k+=1
             t+=k
        elif result[i] == 'X':
             k=0
    print(t)
    #a.append(t)

# for i in range(a):
#     print(a[i])