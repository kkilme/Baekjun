n = int(input())
for i in range(n):
    nn = i
    k = len(str(i))
    for j in range(k):
        nn += int(str(i)[j])
    
    if nn == n : 
     print(i)
     break

if nn != n : print("0")
    