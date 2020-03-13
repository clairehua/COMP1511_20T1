// Writes the square of indexes in an 
// int array and prints them out

// T13A COMP1511 
// 10/03/2020

#include <stdio.h>

#define SIZE 15

// function prototypes
// type name(arguments);
void square_indices(int array[], int size);

void print_array(int array[], int size);

int main(void) {
    int squares[SIZE];

    square_indices(squares, SIZE);
    print_array(squares, SIZE);


    return 0;
}


// Takes an array and puts the square of each index in its array spot
void square_indices(int array[], int size) {
    int i = 0;
    
    while (i < size) {
        array[i] = i * i;
        i++;
    }

    return;
}


void print_array(int array[], int size) {
    int i = 0;
    
    printf("[");
    while (i < size) {
        printf("%d ", array[i]);
        i++;
    }
    printf("]\n");

}











