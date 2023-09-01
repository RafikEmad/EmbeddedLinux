#ifndef MY_HEADER_H
#define MY_HEADER_H

// Constants
#define PI 3.14159265359

// Structure declaration
struct Point {
    int x;
    int y;
};

// Function prototypes
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
double calculateCircleArea(double radius);
void printRectangleInfo(int length, int width);
int findMax(int array[], int size);
int findMin(int array[], int size);
void swap(int *a, int *b);
int factorial(int n);
void printFibonacciSeries(int n);

#endif