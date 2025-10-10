def is_safe(chessboard, row, col, n):

    for i in range(row):
        if chessboard[i][col] == 1:
            return False
    
    i, j = row - 1, col - 1
    while i >= 0 and j >= 0:
        if chessboard[i][j] == 1:
            return False
        i -= 1
        j -= 1
    
    i, j = row - 1, col + 1
    while i >= 0 and j < n:
        if chessboard[i][j] == 1:
            return False
        i -= 1
        j += 1
    
    return True

def foo(chessboard, n, rows, sol):
    if rows == n:
        return sol + 1
    
    for i in range(n):
        if is_safe(chessboard, rows, i, n):
            chessboard[rows][i] = 1
            sol = foo(chessboard, n, rows + 1, sol)
            chessboard[rows][i] = 0
    
    return sol
                
    
n = int(input())
chessboard = [[0 for i in range(n)] for j in range(n)]
solution = foo(chessboard, n, 0, 0)
print(solution)

