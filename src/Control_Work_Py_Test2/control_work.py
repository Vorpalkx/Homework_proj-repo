class Matrix:
    def __init__(self, rows: int, columns: int, values: list):
        self.rows = rows
        self.columns = columns
        self.indx = 0
        
        amount = rows * columns
        if amount < len(values):
            del values[-1 * (len(values) - amount):]
        else:
            for i in range(0, amount - len(values)):
                values.append(0)
        self.values = values
    
    def __iter__(self):
        return self
    
    def __next__(self):
        if self.indx < len(self.values):
            r = self.values[self.indx]
            self.indx += 1
            return r
        self.indx = 0
        raise StopIteration


def mul_const_matrix(const: int, matrix: Matrix):
    for i in range(0, matrix.rows * matrix.columns):
        matrix.values[i] *= const

def addition_matrix(matrix1: Matrix, matrix2: Matrix):
    if (matrix1.rows == matrix2.rows) + (matrix2.columns == matrix2.columns) != 2:
        print("The matrices have different sizes")
        return 0
    
    rows = matrix1.rows
    columns = matrix1.columns
    matrix = Matrix(rows, columns, [0])
    for i in range(0, rows * columns):
        matrix.values[i] = matrix1.values[i] + matrix2.values[i]
    
    return matrix

def matrix_det(matrix: Matrix):
    if matrix.rows != matrix.columns:
        print("The matrix is not square")
        return 0
        
    length = matrix.rows
    values = matrix.values
    det = 0
    if length == 1:
        det = values[0]
    else:
        for i in range(0, length):
            new_values = []
            for j in range(length, length**2):
                if j % length != i:
                    new_values.append(values[j])
            new_matrix = Matrix(length - 1, length - 1, new_values)
            sign = 1 if (i % 2) == 0 else -1
            det += sign * matrix_det(new_matrix) * values[i]
    return det

matrix = Matrix(4,4,[3,-3,-5,8,-3,2,4,-6,2,-5,-7,5,-4,3,5,-6])
