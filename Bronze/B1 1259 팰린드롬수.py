while (True):
    a = input()
    if a == '0' : break

    k = []
    t = True

    for i in range(len(a)):
        k.append(a[len(a)-i-1])
    
    for j in range(len(a)):
        if a[j] != k[j]:
            print("no")
            t = False
            break
        
    if t : print("yes")