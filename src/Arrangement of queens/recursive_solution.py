def placement_queens(array, n, rows, sol):
    # Iterating through each position in one row
    for position in range(1, n + 1):
        array[rows] = position

        # Excluding options with an intersection
        flag = 1
        for i in range(rows):
            if array[i] == array[rows] or abs(array[i] - array[rows]) == abs(
                i - rows
            ):
                flag = 0
                break

        if flag == 1:
            if rows != n - 1:
                sol = placement_queens(array, n, rows + 1, sol)
            else:
                sol += 1
    return sol


n = int(input())
array = [0 for i in range(n)]
solution = placement_queens(array, n, 0, 0)
print(solution)
