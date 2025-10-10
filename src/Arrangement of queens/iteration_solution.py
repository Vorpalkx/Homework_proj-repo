import itertools
n = int(input())

k = 0
for permutations in itertools.permutations(range(n)):
    flag = 1
    for i in range(n):
        for j in range(i+1,n):
            if abs(permutations[i]-permutations[j]) == abs(i - j):
                flag = 0
                break
        if flag == 0:
            break
    if flag == 1:
        k += 1
print(k)
