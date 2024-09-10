a, b = map(int, input().split())
color = []
diff = []
for i in range(a):
     color.append(input())

for i in range(a-7):
    for j in range(b-7):
        W = 0
        B = 0
        for k in range(i,i+8):
            for l in range(j,j + 8):
                if (k + l) % 2 == 0:
                    if color[k][l] != 'W':
                        W += 1
                    if color[k][l] != 'B':
                        B += 1
                else:
                    if color[k][l] != 'B':
                        W += 1
                    if color[k][l] != 'W':
                        B += 1
        diff.append(W)
        diff.append(B)

        
print(min(diff))