# Checking the correctness of the placed queen
def is_safe(chessboard, row, col, n):
    # Checking for being in the same column
    for i in range(row):
        if chessboard[i][col] == 1:
            return False

    # Checking for being in the same diagonal (left-top)
    i, j = row - 1, col - 1
    while i >= 0 and j >= 0:
        if chessboard[i][j] == 1:
            return False
        i -= 1
        j -= 1

    # Checking for being in the same diagonal (right-top)
    i, j = row - 1, col + 1
    while i >= 0 and j < n:
        if chessboard[i][j] == 1:
            return False
        i -= 1
        j += 1

    return True


# Calculation of all correct arrangements of queens in a two-dimensional array
def placement_queens(chessboard, n, rows=0, sol=0):
    if rows == n:
        return sol + 1

    # Checking for the ability to position the queen correctly
    for i in range(n):
        if is_safe(chessboard, rows, i, n):
            chessboard[rows][i] = 1
            sol = placement_queens(chessboard, n, rows + 1, sol)
            chessboard[rows][i] = 0

    return sol


n = int(input())
chessboard = [[0 for i in range(n)] for j in range(n)]
solution = placement_queens(chessboard, n)
print(solution)
