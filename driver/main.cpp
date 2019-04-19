#include"graal.h"
#include<vector>
#include<iostream>

/// Auxiliary function to print an entire array.
void printArray(int *first, int *last)
{
    std::cout << "{ ";
    while(first != last-1){
        std::cout << *first << ", ";
        first++;
    }
    std::cout << *(last-1) << " }" << std::endl;
}

/// Auxiliary function to obtain if the first parameter (x) is smaller than the second (y). Returns true if it is.
bool isSmaller( void *x, void *y)
{
    int *myX = (int*)x;
    int *myY = (int*)y;
    return *myX < *myY;
}

int main(int argc, char const *argv[])
{
    int a[]{1,2,3,3,3,4,5,-1,-1, 4, 666};

    int *index = (int*) graal::min(std::begin(a), std::end(a), sizeof(int), isSmaller);

    printArray(std::begin(a), std::end(a));
    std::cout << "Smallest element of the above array is "<< *index << " at index " << std::distance(std::begin(a), index) << std::endl;

    return 0;
}

