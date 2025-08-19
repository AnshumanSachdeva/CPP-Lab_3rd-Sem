// 1. Print Address and Value of a Variable 
// Write a program to declare an integer variable. Use a pointer to print the address and 
// value of that variable. 
#include <stdio.h>

int main() {
    
    int val; 
    printf("Enter any integer \n");
    scanf("%d",&val);

    int *ptr;
    ptr = &val;
    printf("Address using pointer is %d \n", ptr);
    printf("Value using pointer is %d \n", *ptr);
    
    return 0;
}