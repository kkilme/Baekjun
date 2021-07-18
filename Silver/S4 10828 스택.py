import sys

n = int(input())
stack = []

def push(j):
    stack.append(j)

def pop():
    try : print(stack.pop())
    except : print('-1')

def size():
    print(len(stack))

def empty():
    if len(stack) == 0 : print('1')
    else : print('0')

def top():
    try : print(stack[len(stack)-1])
    except : print('-1')


for i in range(n):
    k = list(sys.stdin.readline().split())
    command = k[0]

    if command == 'push' : push(k[1])
    elif command == 'pop' : pop()
    elif command == 'size' : size()
    elif command == 'empty' : empty()
    elif command == 'top' : top()
