a = []
string = input('Enter the numbers to sort by, separated by spaces: ')

# Adding the entered numbers to the array
flag = 1
tmp = ''
for i in range(0, len(string)):
    if string[i] == ' ':
        flag = 0
    elif flag == 0:
        flag = 1
        tmp = string[i]
    else:
        tmp += string[i]
        if i + 1 == len(string) or string[i + 1] == ' ':
            a.append(int(tmp))

# Sorting an array
for i in range(1, len(a)):
    while i != 0 and a[i - 1] > a[i]:
        x = a[i]
        a[i] = a[i - 1]
        a[i - 1] = x
        i -= 1

print(a)
