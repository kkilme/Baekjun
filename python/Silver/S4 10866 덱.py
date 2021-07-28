import sys

n = int(input())
deque = []

def push(i, j):
    if i == 'front': deque.insert(0,j)
    elif i == 'back' : deque.append(j)

def pop(i):
    if i == 'front' :
        try : print(deque.pop(0))
        except : print('-1')
    elif i == 'back' :
        try : print(deque.pop())
        except : print('-1')

def size():
    print(len(deque))

def empty():
    if len(deque) == 0 : print('1')
    else : print('0')

def front():
    try : print(deque[0])
    except : print('-1')

def back():
    try : print(deque[len(deque)-1])
    except : print('-1')


for i in range(n):
    k = list(sys.stdin.readline().split())
    command = k[0]

    if command == 'push_front' : push('front', k[1])
    elif command == 'push_back' : push('back', k[1])
    elif command == 'pop_front' : pop('front')
    elif command == 'pop_back' : pop('back')
    elif command == 'size' : size()
    elif command == 'empty' : empty()
    elif command == 'front' : front()
    elif command == 'back' : back()
