#include<stdio.h>
#include"square.h"
#include"rectangle.h"
#include"circle.h"

int main()
{
    double radius = 5.0;
    double side = 4.0;
    double lenght = 6.0;
    double width = 5.0;
    
    // double circle_area = calculate_circle_area(radius);
    // double square_area = calculate_square_area(side);
    // double recatangle_area = calculate_rectangle_area(lenght, width);

    printf("Area of Circle: %.2f\n", calculate_circle_area(radius));
    printf("Area of Square: %.2f\n", calculate_square_area(side));
    printf("Area of Rectangle: %.2f\n", calculate_rectangle_area(lenght,width));

    return 0;
}


    




