#include <stdio.h>


// prototype

void sum_and_square(int a, int b, int *sum, int *square);

int main(void) {
    
    int num1, num2;
    int sumEnd;
    int square;

    printf("Please enter two numbers to sum: ");
    scanf("%d %d", &num1, &num2);
    
       
    sum_nums(num1, num2, &sumEnd);
    
    printf("The sum of %d and %d is %d\n", num1, num2, sumEnd);

    return 0;
}

// returns the sum of a and b, and the square of a
void sum_and_square(int a, int b, int *sum, int *square) {
    *sum = a + b;
    *square = a * a;
    
}
