def sol(n, start, middle, end):
    if n == 1:           
        print(start+' '+end)
        
    else:
        sol(n-1, start, end, middle)
        sol(1, start, middle, end)
        sol(n-1, middle, start, end)

a = int(input())
print(2**a-1)
if a<21 : sol(a,'1','2','3')