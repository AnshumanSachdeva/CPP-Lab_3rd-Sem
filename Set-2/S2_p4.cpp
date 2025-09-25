#include <iostream>
using namespace std;

void matrixAdd(int *mat1, int *mat2, int *result, int m, int n) {
    for (int i = 0; i < m * n; i++) {
        *(result + i) = *(mat1 + i) + *(mat2 + i);
    }
}

int main() {
    int m, n;
    cin >> m >> n;

    int mat1[100], mat2[100], result[100];

    for (int i = 0; i < m * n; i++) {
        cin >> *(mat1 + i);
    }

    for (int i = 0; i < m * n; i++) {
        cin >> *(mat2 + i);
    }

    matrixAdd(mat1, mat2, result, m, n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << *(result + i * n + j) << " ";
        }
        cout << endl;
    }

    return 0;
}
