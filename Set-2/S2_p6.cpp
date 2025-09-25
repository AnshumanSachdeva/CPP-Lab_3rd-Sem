#include <iostream>
using namespace std;

void rowWiseMax(int *mat, int m, int n, int *maxArr) {
    for (int i = 0; i < m; i++) {
        int maxVal = *(mat + i * n);
        for (int j = 1; j < n; j++) {
            if (*(mat + i * n + j) > maxVal) {
                maxVal = *(mat + i * n + j);
            }
        }
        *(maxArr + i) = maxVal;
    }
}

int main() {
    int m, n;
    cin >> m >> n;

    int mat[100], maxArr[100];

    for (int i = 0; i < m * n; i++) {
        cin >> *(mat + i);
    }

    rowWiseMax(mat, m, n, maxArr);

    for (int i = 0; i < m; i++) {
        cout << *(maxArr + i) << " ";
    }
    cout << endl;

    return 0;
}
