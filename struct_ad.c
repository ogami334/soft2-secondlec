#include <stdio.h>

typedef struct data {
    int x;
    double y;
    char z;
    long long int n;
    float u;
} Data;

int main() {
    Data data1;
    printf("%p\n",&(data1.x));
    printf("%p\n",&(data1.y));
    printf("%p\n",&(data1.z));
    printf("%p\n",&(data1.n));
    printf("%p\n",&(data1.u));
}
