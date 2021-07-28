import sys
# import time

# card_num = int(input())
# card = sys.stdin.readline().split()


# iscard_num = int(input())
# iscard = sys.stdin.readline().split()
# t = time.time()


# for k in range(iscard_num):
#     print(card.count(iscard[k]), end=' ')
card_n = int(input())
card_d = dict()
card_l = sys.stdin.readline().split()
iscard_n = int(input())
iscard_l = sys.stdin.readline().split()
for i in card_l:
    if i in card_d : card_d[i]+=1
    else : card_d.update({i:1})

for j in iscard_l:
    try:
         print(card_d[j], end=" ")
    except: print('0', end=' ')
