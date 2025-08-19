// 3. Increment a Variable using Pointer Parameter 
// Write a function void increment(int *p) that increases the value of an integer by 1. Pass 
// the variable’s address to this function and print the updated value. 
#include <stdio.h>
int updateValue(int *a){
    return *a + 1;
}

int main() {
    int val = 10;
    val = updateValue(&val);
    printf("Value after updation is %d \n", val);
    return 0;
}