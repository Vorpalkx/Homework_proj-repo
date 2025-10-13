import itertools

n = int(input())
counter = 0

# Going through all possible combinations
for permutations in itertools.permutations(range(n)):
    flag = 1
    # Excluding options with an intersection
    for i in range(n):
        for j in range(i + 1, n):
            if abs(permutations[i] - permutations[j]) == abs(i - j):
                flag = 0
                break
        if flag == 0:
            break
    if flag == 1:
        counter += 1

print(counter)
