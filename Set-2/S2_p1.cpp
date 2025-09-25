#include <iostream>
using namespace std;

void findMaxMin(int *arr, int n, int &maxVal, int &minVal) {
    maxVal = *arr;
    minVal = *arr;
    for (int i = 1; i < n; i++) {
        if (*(arr + i) > maxVal) {
            maxVal = *(arr + i);
        }
        if (*(arr + i) < minVal) {
            minVal = *(arr + i);
        }
    }
}

int main() {
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) {
        cin >> *(arr + i);
    }

    int maxVal, minVal;
    findMaxMin(arr, n, maxVal, minVal);

    cout << maxVal << endl;
    cout << minVal << endl;

    return 0;
}
