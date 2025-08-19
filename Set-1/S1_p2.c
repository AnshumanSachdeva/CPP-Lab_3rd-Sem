// 2. Swap Two Numbers (Call by Value vs Call by Reference) 
// Write two functions: 
// • One that swaps numbers using call by value. 
// • One that swaps numbers using call by reference (pointers). 
// Show the difference in output. 
#include <stdio.h>

void swapByValue(int a, int b){
    int c;
    c = a;
    a = b;
    b = c;

}
void swapByReference(int *p, int *q){
    int c;
    c = *p;
    *p = *q;
    *q = c;
}

int main() {
    
    int a,b;
    printf("Enter two numbers \n");
    scanf("%d %d", &a, &b);

    swapByValue(a, b);
    printf("After call by reference a = %d and b = %d \n", a,b);

    swapByReference(&a, &b);
    printf("After call by reference a = %d and b = %d \n", a,b);
    
    return 0;
}