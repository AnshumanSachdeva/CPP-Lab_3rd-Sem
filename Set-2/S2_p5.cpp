#include <iostream>
using namespace std;

void transpose(int *mat, int *trans, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            *(trans + j * n + i) = *(mat + i * n + j);
        }
    }
}

int main() {
    int n;
    cin >> n;

    int mat[100], trans[100];

    for (int i = 0; i < n * n; i++) {
        cin >> *(mat + i);
    }

    transpose(mat, trans, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << *(trans + i * n + j) << " ";
        }
        cout << endl;
    }

    return 0;
}
