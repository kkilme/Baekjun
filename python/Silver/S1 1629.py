def sol(a, b, c): # 분할 정복을 이용한 거듭제곱
    r = 1
    while b:
        if b % 2 == 1:
            r *= a
        a *= a
        r %= c
        a %= c
        b //= 2
        
    return r

a, b, c = map(int, input().split())
print(sol(a,b,c))
# namuji = []
# n = a
# if b == 1: print(a%c)
# else:
#     n %= c
#     a*= n
#     if a%c not in namuji:
#         namuji.append(a%c)
#     a %= c
#     for i in range(b-1):
#         # print(a%c)
#         a *= n
#         if a%c not in namuji:
#             namuji.append(a%c)
#         else:
#             break
#         a %= c
#     k = b % len(namuji)
#     print(len(namuji))
#     if len(namuji) == 2 or len(namuji) == 1: print(namuji[k])
#     else: print(namuji[k-2])
