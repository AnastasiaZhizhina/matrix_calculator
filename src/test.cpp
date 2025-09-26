#include "matrix.h"
#include <cassert>  // для assert
#include <iostream>

// Тест сложения матриц
void test_matrix_addition() {
    Matrix A = create_matrix(2, 2);
    Matrix B = create_matrix(2, 2);
    
    // Заполнение тестовыми данными
    A.data[0][0] = 1; A.data[0][1] = 2;
    A.data[1][0] = 3; A.data[1][1] = 4;
    B.data[0][0] = 5; B.data[0][1] = 6;
    B.data[1][0] = 7; B.data[1][1] = 8;
    Matrix result = matrix_add(A, B);
    assert(result.data[0][0] == 6);  // 1+5
    assert(result.data[0][1] == 8);  // 2+6
    assert(result.data[1][0] == 10); // 3+7
    assert(result.data[1][1] == 12); // 4+8
    free_matrix(A);
    free_matrix(B);
    free_matrix(result);
}
// Тест обработки ошибок
void test_invalid_addition() {
    Matrix A = create_matrix(2, 2);
    Matrix B = create_matrix(3, 3); // Несовместимые размеры!
    try {
        Matrix result = matrix_add(A, B);
        assert(false); // Не должно сюда попасть!
    } catch (const std::exception& e) {
        assert(std::string(e.what()).find("dimensions") != std::string::npos);
    }
}

// Добавьте это в конец файла test.cpp
int main() {
    test_matrix_addition();
    test_invalid_addition();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}