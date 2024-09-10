a, b, c = map(int, input().split())

if a==b and b==c:
    print(a*1000 + 10000)
elif a==b or b==c or a==c:
    print(1000+ (a if a==b or a==c else b) * 100)   
else:
    print(max(a,b,c)*100)