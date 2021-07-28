a,b = map(int, input().split())
c = int(input())

total_m = a*60 + b + c

print(((total_m // 60)%24), total_m%60)