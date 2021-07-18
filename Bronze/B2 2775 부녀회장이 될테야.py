t = int(input())

def num(floor, door):
    global l
    for i in range(1,door+1):
        l[0].append(i)
    
    for j in range(1,floor+1):
        for k in range(1,door+1):
            s = 0
            for m in range(k):
                s += l[j-1][m]
            l[j].append(s)
    return l[floor][door-1]

    

for i in range(t):
    l = []
    k = int(input())
    n = int(input())
    for p in range(k+1):
        l.append([])
    
    print(num(k,n))


# 1 2 3 4 5
# 1 3 6 10 15
# 1 4 10 20 35
# 1 5 15 35 70
# 1 6 21 56 126