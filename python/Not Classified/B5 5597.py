arr = []
for i in range(30):
    arr.append(i+1)
for i in range(28):
    arr.remove(int(input()))
print(arr[0])
print(arr[1])