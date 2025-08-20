// 10. Pointer to Array vs Array of Pointers 
// Write a program to demonstrate the difference between: 
// • A pointer to an array (int (*p)[5]) 
// • An array of pointers (int *arr[5]) 
// Show how elements are accessed in both cases. 
#include <stdio.h>

int main() {
    
    // int (*p)[5];    // this means pointer to an array or we can say that a pointer pointing to an array of integers

    // int *arr[5];    // this means array of pointer or we can say that an array containing pointers of integer type

    // -------- Pointer to an Array --------
    int nums[5] = {10, 20, 30, 40, 50};
    int (*p)[5] = &nums;  // p is a pointer to an array of 5 integers

    printf("Pointer to Array (int (*p)[5]):\n");
    for (int i = 0; i < 5; i++) {
        printf("Element %d: %d\n", i, (*p)[i]);  
    }

    printf("\n");

    // -------- Array of Pointers --------
    int a = 100, b = 200, c = 300, d = 400, e = 500;
    int *arr[5] = {&a, &b, &c, &d, &e};  // arr is array of 5 int pointers

    printf("Array of Pointers (int *arr[5]):\n");
    for (int i = 0; i < 5; i++) {
        printf("Element %d: %d\n", i, *arr[i]);
    }

    return 0;
}