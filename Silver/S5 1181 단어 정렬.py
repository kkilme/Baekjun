import sys

n = int(input())
word = []
for j in range(n):
    w = sys.stdin.readline().rstrip()
    if w in word :
       pass
    else : 
       word.append(w)

word = sorted(word, key= lambda x : (len(x), x))
for i in word: print(i)