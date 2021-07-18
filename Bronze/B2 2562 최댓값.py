numbers = []

for _ in range(9):
    numbers.append(int(input()))

m = max(numbers)

print(m)
print(numbers.index(m)+1)