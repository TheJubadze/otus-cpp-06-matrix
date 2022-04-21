#include "Log.h"
#include "matrix.h"

int main(int, char **) {
    Log::Log::Init();
    MY_INFO("========================================");

    auto mat = Matrix<int, -55>();
    auto kv = mat[100];
    kv[100];
    mat[100][100] = 458;

    MY_INFO(mat[100][100]);
    MY_INFO(mat[0][0]);

    return 0;
}

