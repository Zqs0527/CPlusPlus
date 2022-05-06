#include <iostream>
#include <cstdio>

int main(int, char**) {
    int x = 42;
    const int & y = x;
    int * ip = &x;

    printf("the value of x is %d\n", x);
    printf("the value of y is %d\n", y);
    printf("the value of *ip is %d\n", *ip);

   
    printf("the value of x is %d\n", x);
    printf("the value of y is %d\n", y);
    printf("the value of *ip is %d\n", *ip);

    int z = 10;
    ip = &z;
    printf("the value of *ip is %d\n", *ip);


    // x = 6;
    // printf("the value of *ip is %d\n", *ip);
    puts("Hello, world!\n");
}
