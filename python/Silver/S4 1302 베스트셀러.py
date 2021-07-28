import sys
n = int(input()) #책의 개수
book = {} #책 dict
for j in range(n):
    b = sys.stdin.readline().rstrip()
    if b in book : #입력된 책이 book에 있으면 해당 책의 value+1
       book[b]+=1
    else : #없으면 생성 후 value=1
       book.update({b:1})

new_book = sorted(book.items(), key= lambda x : x[1],reverse=True) #1차 정렬 - value를 기준으로 내림차순

m = new_book[0][1] #value 최대값 = m
new_new_book = [] #value가 같은 책이 있을 경우를 위한 배열

if len(new_book) == 1 : print(new_book[0][0]) #책이 하나라면 그냥 출력
elif new_book[1][1] == m : #value가 같은책이 있다면
   for i in range(len(new_book)): #value가 같지 않은 책 나올때까지 새로운 배열에 책 이름을 저장
      if new_book[i][1] == m :
       new_new_book.append(new_book[i][0])
      else : break
   new_new_book = sorted(new_new_book) #사전순 정렬
   print(new_new_book[0])

else : print(new_book[0][0]) #value가 같은책이 없다면 처음 책 출력