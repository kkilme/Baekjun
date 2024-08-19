# 균형잡힌 세상
# 괄호 검사
match = {')':'(', ']': '['}
while True:
    s = input()
    stk = []
    f = True
    if s == '.': break
    for c in s:
        if c == '(' or c == '[':
            stk.append(c)
        if c in match.keys():
            if not stk or stk.pop() != match[c]:
                f = False
                break
    if f and not stk: print("yes")
    else: print("no")