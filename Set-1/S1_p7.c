// 7. Reverse an Array (Pointer Parameter) 
// Write a function void reverse(int *arr, int n) that reverses the elements of an array in place 
// using pointers. 
#include <stdio.h>
void reverse(int *arr, int n){
    int *ptr = &arr[n-1];
    for (int i = 0; i < n; i++)
    {
        printf("%d", *ptr);
        printf(" ");
        ptr--;
    }
}

int main() {
    int n;
    printf("Enter size of array\n");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    reverse(&arr, n);
    return 0;
}