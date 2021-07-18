a,b,c = map(int, input().split())
d = int(input())

total_s = a*3600 + b*60 + c + d

print(((total_s // 3600)%24), (total_s//60)%60, total_s%60)