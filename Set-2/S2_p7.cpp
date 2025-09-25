#include <iostream>
using namespace std;

int sum3DArray(int *arr, int x, int y, int z) {
    int sum = 0;
    for (int i = 0; i < x * y * z; i++) {
        sum += *(arr + i);
    }
    return sum;
}

int main() {
    const int x = 2, y = 2, z = 2;
    int arr[x][y][z];

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cin >> arr[i][j][k];
            }
        }
    }

    int totalSum = sum3DArray(&arr[0][0][0], x, y, z);
    cout << totalSum << endl;

    return 0;
}
