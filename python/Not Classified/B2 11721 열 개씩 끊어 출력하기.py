string = input()
for i in range((len(string)//10)+1):
    print(string[i*10:(i+1)*10])