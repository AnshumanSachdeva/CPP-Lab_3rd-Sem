// 4. Sum of Two Numbers using Pointers 
// Write a function that takes two integer pointers as parameters and returns their sum. Call 
// this function in main. 
#include <stdio.h>
int sum(int *a, int *b){
    return (*a + *b);
}
int main() {
    
    int a, b;
    a = 10;
    b = 20;
    int result = sum(&a,&b);
    printf("Sum is %d \n", result);
    return 0;
}