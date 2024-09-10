word = input().upper()
word_n = list(set(word))
al_n = []
for k in range(len(word_n)):
    al_n.append(word.count(word_n[k]))

if al_n.count(max(al_n)) > 1:
    print('?')
else:
    print(word_n[al_n.index(max(al_n))])
