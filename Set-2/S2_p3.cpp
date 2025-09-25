#include <iostream>
using namespace std;

void sumEvenOdd(int *arr, int n, int &sumEven, int &sumOdd) {
    sumEven = 0;
    sumOdd = 0;
    for (int *ptr = arr; ptr < arr + n; ptr++) {
        if (*ptr % 2 == 0) {
            sumEven += *ptr;
        } else {
            sumOdd += *ptr;
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

    int sumEven, sumOdd;
    sumEvenOdd(arr, n, sumEven, sumOdd);

    cout << sumEven << endl;
    cout << sumOdd << endl;

    return 0;
}
