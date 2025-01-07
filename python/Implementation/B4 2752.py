# 2025-01-06 세수정렬
# 구현
a, b, c = map(int, input().split())

if(a<b<c): print(a, b, c)
if(b<a<c): print(b, a, c)
if(b<c<a): print(b, c, a)
if(c<a<b): print(c, a, b)
if(c<b<a): print(c, b, a)
if(a<c<b): print(a, c, b)