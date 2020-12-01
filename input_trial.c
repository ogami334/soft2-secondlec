#include <stdio.h>
/*int main(int argc,char **argv) {
    double x;
    double y;
    double z;
    double a;
    double b;
    int flag=0;
    FILE *fp;
    if ((fp=fopen(argv[1],"r"))!=NULL) {
        while () {
            int flag=fscanf(fp,"%lf %lf %lf %lf %lf",&x,&y,&z,&a,&b);
            printf("%d\n",flag);
            if (flag==0) {
                break;
            }
            if (flag>0) {
                printf("%lf %lf %lf %lf %lf\n",x,y,z,a,b);            
            }
        }
        //flag =fscanf(fp,"%lf %lf %lf %lf %lf%*1[#]",&x,&y,&z,&a,&b);
    }
}*/
int main(int argc,char **argv) {
    double x;
    double y;
    double z;
    double a;
    double b;
    char buf[100];
    int flag=0;
    FILE *fp;
    if ((fp=fopen(argv[1],"r"))!=NULL) {
        for (int i=0;i<5;i++) {
        if (fgetc(fp)=='#') {
            char trash[100];
            printf("%d\n",fscanf(fp,"%[^\n]*1[\n]",trash));
            printf("True\n");
        }
        else {
            printf("%d\n",fscanf(fp,"%lf %lf %lf %lf %lf%[^\n]*1[\n]",&x,&y,&z,&a,&b,buf));
            printf("%lf %lf %lf %lf %lf\n",x,y,z,a,b);

        }

        }
    }
}