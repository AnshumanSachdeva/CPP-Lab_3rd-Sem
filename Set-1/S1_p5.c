// 5. Find Maximum of Three Numbers (Using Pointers as Parameters) 
// Write a function int max(int *a, int *b, int *c) that returns the largest of three numbers. 
#include <stdio.h>
int max(int *a, int *b, int *c){
    if (*a > *b && *a > *c)
    {
        return *a; 
    } else if (*b > *a && *b > *c){
        return *b;
    } else {
        return *c;
    }
    
}
int main() {
    int a,b,c;
    a = 10;
    b = 20;
    c = 30;
    int result = max(&a,&b,&c);
    printf("Maximum of three no's is :%d \n", result);
    
    return 0;
}