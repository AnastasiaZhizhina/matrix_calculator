#ifndef MATRIX_H
#define MATRIX_H

#include <stdexcept>
#include <iostream>

typedef struct {
    double** data;    // Указатель на двумерный массив данных
    int rows;         // Количество строк в матрице
    int cols;         // Количество столбцов в матрице
} Matrix;

// Создание и освобождение
Matrix create_matrix(int rows, int cols);
void free_matrix(Matrix m);

// Базовые операции
Matrix matrix_add(Matrix a, Matrix b);
Matrix matrix_multiply(Matrix a, Matrix b);
Matrix matrix_transpose(Matrix m);

// Вспомогательные
void print_matrix(Matrix m);
Matrix matrix_from_array(double* data, int rows, int cols);

/**
 * @brief Умножение двух матриц
 * 
 * @param a Первая матрица (размер M×N)
 * @param b Вторая матрица (размер N×K)
 * @return Matrix Результирующая матрица (размер M×K)
 * @note Время выполнения: O(M*N*K)
 * @warning Матрицы должны быть совместимы по размерам!
 * @exception Выбрасывает std::invalid_argument если cols(a) != rows(b)
 */
Matrix matrix_multiply(Matrix a, Matrix b);

#endif