import string

alp = list(string.ascii_lowercase)
let = list(str(input()))

for j in range(len(alp)):
    if alp[j] in let:
        print(let.index(alp[j]), end=" ")
    else: print("-1", end=" ")