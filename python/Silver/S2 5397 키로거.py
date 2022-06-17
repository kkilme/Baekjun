import collections
n = int(input())
for _ in range(n):
    rawpass = input().strip()
    password = collections.deque() # deque: doubly linked list로 구현되어 있음
    temppass = collections.deque() # 커서 이동을 구현할 임시 스택
    for c in rawpass:
        if c == '<':
            if len(password) != 0: temppass.append(password.pop())
        elif c == '>':
            if len(temppass) != 0: password.append(temppass.pop())
        elif c == '-':
            if len(password) != 0: password.pop()
        else: password.append(c)
    for _ in range(len(temppass)): password.append(temppass.pop())

    print(''.join(password))
