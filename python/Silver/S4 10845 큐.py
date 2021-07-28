import sys

n = int(input())
queue = []

def push(j):
    queue.append(j)

def pop():
    try : print(queue.pop(0))
    except : print('-1')

def size():
    print(len(queue))

def empty():
    if len(queue) == 0 : print('1')
    else : print('0')

def front():
    try : print(queue[0])
    except : print('-1')

def back():
    try : print(queue[len(queue)-1])
    except : print('-1')


for i in range(n):
    k = list(sys.stdin.readline().split())
    command = k[0]

    if command == 'push' : push(k[1])
    elif command == 'pop' : pop()
    elif command == 'size' : size()
    elif command == 'empty' : empty()
    elif command == 'front' : front()
    elif command == 'back' : back()
