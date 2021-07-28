a, b = map(int, input().split())
color = []
diff = []
board1 = 'WBWBWBWB'
board2 = 'BWBWBWBW'
for i in range(a):
     color.append(input())

for i in range(a-7):
    for j in range(b-7):
        dif = 0
        for k in range(i, i+8):
            for l in range(j, j+8):  
                if k % 2 == 0:
                     if j % 2 == 0:
                         if color[k][l] != board1[l-j]: dif+= 1
                     else :
                         if color[k][l] != board2[l-j]: dif+= 1
                else :
                     if j % 2 == 0:
                         if color[k][l] != board2[l-j]: dif+= 1
                     else :
                         if color[k][l] != board1[l-j]: dif+= 1
        diff.append(dif)
      
print(min(diff))