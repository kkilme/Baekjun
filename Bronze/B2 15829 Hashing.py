L = int(input())
word = input()
M = 1234567891
t = 0
for i in range(len(word)):
    t += 31**i*(ord(word[i]) - ord('a') + 1)

print(t%M)