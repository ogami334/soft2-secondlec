#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct point {
    double x;
    double y;

} Point;

void center(double *X,double *Y,const Point *list) {
    double xr=0;
    double yr=0;
    for (int i=0;i<1000;i++) {
        xr += (list+i)->x;
        yr += (list+i)->y;
    }
    *X = xr/ 1000;
    *Y = yr/ 1000;

}


int main() {
    double max=100;
    double min=-100;
    srand(time(NULL));
    Point ps[1000]; 
    for (int i=0;i<1000;i++) {
        ps[i] = (Point){ .x =min +(max-min) * ( (double) rand()/RAND_MAX ) ,
                         .y =min +(max-min) * ( (double) rand()/RAND_MAX ) };
    };

    double resx;
    double resy;
    center(&resx,&resy,ps);
    printf("%lf %f\n",resx,resy);
}