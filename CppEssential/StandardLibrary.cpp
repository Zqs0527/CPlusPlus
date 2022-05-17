#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>

int main()
{
    // static const char * fin1 = "file1";
    // static const char * fin2 = "file2";
    // rename(fin1, fin2);
    // remove(fin2);
    // FILE * fileHandler = fopen(fin1, "w");
    // fclose(fileHandler);
    // puts("Done");
    double i = -45;
    double absoluteValue = exp(4);
    printf("the absolut value is %lf\n", absoluteValue);
    const double pi = acos(-1);
    double x = sin(pi/2);
    printf("x is %lf\n", x);

    printf("time value: %ld\n", (long) time(nullptr));

    srand((unsigned)time(nullptr));
    rand(); // there might be pattern if this line doesn't exist

    printf("pseudo-random value: %d\n", rand() % 1000);
    printf("pseudo-random value: %d\n", rand() % 1000);
    printf("pseudo-random value: %d\n", rand() % 1000);

    printf("RAND_MAX is %d\n", RAND_MAX);

    fputs("Hello world!\n",stdout);
    const int bufferSize = 256;
    static char buffer[bufferSize];
    fputs("Prompt: ",stdout);
    fgets(buffer, bufferSize, stdin);
    puts("output: ");
    fputs(buffer, stdout);
    fflush(stdout);
    return 0;
}