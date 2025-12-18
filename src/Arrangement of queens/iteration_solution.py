import itertools

def total_n_queens(n: int) -> int:
    counter = 0
    # Going through all possible combinations
    for permutations in itertools.permutations(range(n)):
        flag = True
        # Excluding options with an intersection
        for i in range(n):
            for j in range(i + 1, n):
                if abs(permutations[i] - permutations[j]) == abs(i - j):
                    flag = False
                    break
            if not flag:
                break
        if flag:
            counter += 1
    return counter

n = int(input())
amount = total_n_queens(n)
print(amount)
