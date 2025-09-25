#include <iostream>
using namespace std;

int main() {
    const int n = 5;
    const char *names[n] = {"Alice", "Bob", "Charlie", "David", "Eve"};

    const char **ptr = names;

    for (int i = 0; i < n; i++) {
        cout << *(ptr + i) << endl;
    }

    return 0;
}
