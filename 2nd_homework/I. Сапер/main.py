#1. Создание матрицы
#2. Заполнение матрицы инфой о минах(Функция Check для сведений о минах у соседей)
#3. Вывод матрицы на консоль


def Create_Matrix(rows, cols):
    matrix = [0] * rows
    for i in range(rows):
        matrix[i] = [0] * cols
    return matrix


def Init_Mtrix(matrix, coordinate_bombs):
    counter = 0
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            bomb_i, bomb_j = 0, 0
            if counter != len(coordinate_bombs):
                bomb_i, bomb_j = coordinate_bombs[counter]
            if i == bomb_i - 1 and j == bomb_j - 1:
                matrix[i][j] = "*"
                counter += 1
            else:
                for bomb in coordinate_bombs:
                    bomb_i, bomb_j = bomb
                    if abs(((bomb_i - 1) - i) ** 2 + ((bomb_j - 1) - j) ** 2) <= 2:
                        matrix[i][j] += 1


N, M, K = map(int, input().split())
bombs_i_j = []
for i in range(K):
    bomb_i_j = tuple(map(int, input().split()))
    bombs_i_j.append(bomb_i_j)
Matr = Create_Matrix(N, M)
if K != 0:
    Init_Mtrix(Matr, bombs_i_j)
for i in range(N):
    for j in range(M):
        print(Matr[i][j], end=" ")
    print()
