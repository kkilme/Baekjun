a = int(input())

if a == 4 or a == 7 : print(-1)
elif a%5 == 0 : print(a//5)
elif a%5 == 1 or a%5 == 3 : print(a//5 + 1)
elif a%5 == 2 or a%5 == 4 : print(a//5 + 2)