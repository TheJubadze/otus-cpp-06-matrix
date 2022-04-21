#include "Log.h"
#include "matrix.h"

int main(int, char **) {
    Log::Log::Init();
    MY_INFO("========================================");

    auto mat = Matrix<int, -55>();
    mat[100][100] = 458;

    MY_INFO(mat[100][100]);
    MY_INFO(mat.Size());
    MY_INFO(mat[0][0]);
    MY_INFO(mat[1][0]);
    MY_INFO(mat[23][0]);
    MY_INFO(mat.Size());

    return 0;
}

