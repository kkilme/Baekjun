a,b = map(int, input().split())

total_m = a*60 + b - 45

print(((total_m // 60)%24), total_m%60)