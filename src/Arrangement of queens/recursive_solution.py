def foo(array, n, rows, sol):
    for position in range(1, n + 1):
        array[rows] = position
        
        flag = 1
        for i in range(rows):
            if array[i] == array[rows] or abs(array[i] - array[rows]) == abs(i - rows):
                flag = 0
                break
        
        if flag == 1:
            if rows != n - 1:
                sol = foo(array, n, rows + 1, sol)
            else:
                sol += 1
    return sol
                    
        
n = int(input())
array = [0 for i in range(n)]
solution = foo(array, n, 0, 0)
print(solution)
