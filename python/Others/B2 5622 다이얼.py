import string

alp = string.ascii_uppercase
numal = input()
num = []
for i in numal:
    k = alp.index(i)
    if 0<=k<=2 : num.append(2)
    elif 3<=k<=5 : num.append(3)
    elif 6<=k<=8 : num.append(4)
    elif 9<=k<=11 : num.append(5)
    elif 12<=k<=14 : num.append(6)
    elif 15<=k<=18 : num.append(7)
    elif 19<=k<=21 : num.append(8)
    elif 22<=k<=25 : num.append(9)
    
print(sum(j+1 for j in num))