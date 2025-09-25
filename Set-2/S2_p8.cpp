#include <iostream>
using namespace std;

void print3DCube(int *cube, int x, int y, int z) {
    for (int i = 0; i < x * y * z; i++) {
        cout << *(cube + i) << " ";
        if ((i + 1) % z == 0) cout << "\n";
        if ((i + 1) % (y * z) == 0) cout << "\n";
    }
}

int main() {
    const int x = 3, y = 3, z = 3;
    int arr[x][y][z];

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cin >> arr[i][j][k];
            }
        }
    }

    print3DCube(&arr[0][0][0], x, y, z);

    return 0;
}
