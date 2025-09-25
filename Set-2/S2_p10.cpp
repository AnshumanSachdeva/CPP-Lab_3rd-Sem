#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        cin >> *(arr + i);
    }

    int sum = 0;
    for (int *ptr = arr; ptr < arr + n; ptr++) {
        sum += *ptr;
    }

    float average = (float)sum/n;
    cout << "Average of elements: " << average << endl;

    delete[] arr;
    return 0;
}
