n = int(input())

for j in range(2*n):

    if n == 1:
        print("*")
        break

    for i in range(n):
        if j % 2 == 0:
            if i % 2 == 0:
                 print("*", end='')
            elif i %2 == 1:
                 print(" ", end='')

        if j %2 == 1:
            if i%2 == 1:
                  print("*", end='')
            elif i %2 == 0:
                 print(" ", end='')
    print("")
    j += 1
