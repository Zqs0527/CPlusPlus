#include <iostream>
#include <cstdio>

int main(int, char**) {
    int x = 42;
    int y = 7;
    int * ip = &x;

    printf("the value of x is %d\n", x);
    printf("the value of y is %d\n", y);
    printf("the value of *ip is %d\n", *ip);

    x = 6;
    printf("the value of *ip is %d\n", *ip);
    puts("Hello, world!\n");
}
