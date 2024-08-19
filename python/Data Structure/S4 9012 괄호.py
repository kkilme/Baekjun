n = int(input())

for i in range(n):
    k = True
    vps = list(input()) #괄호문자열
    if vps.count('(') != vps.count(')'): #개수다르면 no
         k = False
         print("NO")
         
    else : #개수같으면
         for i in range(len(vps)//2):
             if vps[i] == '(' : vps.remove(')') #(이면 )하나씩 지움
             elif k : # ) 가 나타나면 no
                 k = False
                 print('NO')
                 
         if k : print("YES")