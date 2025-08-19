// 7. Reverse an Array (Pointer Parameter) 
// Write a function void reverse(int *arr, int n) that reverses the elements of an array in place 
// using pointers. 
#include <stdio.h>

int main() {
    
    int arr[5];
    printf("Enter array elements : \n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }
    int *ptr = &arr[4];
    for (int i = 0; i < 5; i++)
    {
        printf("%d", *ptr);
        printf(" ");
        ptr--;
    }
    
    return 0;
}