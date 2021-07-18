l = list(input().split())
t = 0
for i in range(len(l)-1): 
    if int(l[0]) == 1 and int(l[i+1]) == int(l[i])+1 : 
         t+=1
    elif int(l[0]) == 8 and int(l[i+1]) == int(l[i])-1 :
         t+=2
    else : 
        print("mixed")
        break

if t == 7 : print("ascending")
elif t == 14 : print("descending")
else : quit()