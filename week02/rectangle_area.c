// takes length and width and prints area
// COMP1511 T13A
// 25/2/2020

#include <stdio.h>

int main(void) {

    int length, width;
    int area;
    printf("Please enter rectangle length: ");
    scanf("%d", &length);
    printf("Please enter rectangle width: ");  
    scanf("%d", &width);
    
    area = length * width;
    printf("Area: %d\n", area);   
    
    return 0;
}
