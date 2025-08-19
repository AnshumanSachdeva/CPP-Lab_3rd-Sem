// 6. Access Array Elements using Pointers 
// Write a program to input 5 integers in an array. Use pointer arithmetic (not indices) to 
// print all the elements. 
#include <stdio.h>

int main() {
    
    int arr[5];
    printf("Enter array elements : \n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }
    int *ptr = arr;
    for (int i = 0; i < 5; i++)
    {
        printf("%d", *ptr);
        printf(" ");
        ptr++;
    }
    
    return 0;
}