#include "Log.h"
#include "matrix.h"
#include <iostream>

int main(int, char **) {
    Log::Log::Init();
    MY_INFO("========================================");

    //бесконечная матрица int заполнена значениями -1
    Matrix<int, -1> matrix;
    assert(matrix.size() == 0); // все ячейки свободны
    auto a = matrix[0][0];
    assert(a == -1);
    assert(matrix.size() == 0);
    matrix[100][100] = 314;
    assert(matrix[100][100] == 314);
    assert(matrix.size() == 1);

    Matrix<int, 0> m0;
    auto size = 10;
    auto ij = 0;
    auto ji = 9;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == j) m0[i][j] = ij++;
            if (i + j == size - 1) m0[i][j] = ji--;
        }
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << m0[i][j] << ' ';
        }
        std::cout << '\n';
    }

    std::cout << m0.size();

    return 0;
}

