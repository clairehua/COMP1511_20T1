#include <stdio.h>


// prototype
void sum_nums(int a, int b, int *sum);

int main(void) {
    
    int num1, num2;
    int sumEnd;

    printf("Please enter two numbers to sum: ");
    scanf("%d %d", &num1, &num2);
    
       
    sum_nums(num1, num2, &sumEnd);
    
    printf("The sum of %d and %d is %d\n", num1, num2, sumEnd);

    return 0;
}

void sum_nums(int a, int b, int *sum) {
    *sum = a + b;
}
