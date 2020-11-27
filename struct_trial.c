#include <stdio.h>

struct point1
{
    int x;
    int y;
};

struct point2
{
    char c;
    int x;
    int y;
};

int main() {
    printf( "%zu\n",sizeof(struct point1));
    printf( "%zu\n",sizeof(struct point2));
}