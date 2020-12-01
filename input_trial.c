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
/*int main(int argc,char **argv) {
    double x;
    double y;
    double z;
    double a;
    double b;
    char buf[100]={};
    int flag=0;
    FILE *fp;
    if ((fp=fopen(argv[1],"r"))!=NULL) {
        for (int i=0;i<6;i++) {
            if (fgetc(fp)=='#') {
                char trash[100]={};
                printf("%d\n",fscanf(fp,"%[^\n]%*1[\n]",trash));
                printf("True\n");
                printf("%s\n",trash);
            }
            else {
                printf("%d\n",fscanf(fp,"%lf %lf %lf %lf %lf %[^\n]%*1[\n]",&x,&y,&z,&a,&b,buf));
                printf("%lf %lf %lf %lf %lf\n",x,y,z,a,b);
                printf("%s\n",buf);
            }   
            printf("\n");
        }
    }
}*/
int main(int argc,char **argv) {
    double x;
    double y;
    double z;
    double a;
    double b;
    char buf[100]={};
    int flag=0;
    FILE *fp;
    if ((fp=fopen(argv[1],"r"))!=NULL) {  
        while (flag==1) {
            char buf[100];
            if ( fscanf(fp,"%[^\n]%*1[\n]",buf) == -1 ) {
                flag=0;
            }
            if (cnt<objnum) {
                cnt
        if (sscanf(buf,"%lf %lf %lf %lf %lf", &objects[cnt].m, &objects[cnt].x, &objects[cnt].y, &objects[cnt].vx, &objects[cnt].vy) ==5) {
          cnt+=1;
        }
      }
      else {
        flag=1;
      }
    }
        for (int i=0;i<6;i++) {
            char buf[100];
            double a;
            double b;
            double c;
            double d;
            double e;
            printf("%d\n",fscanf(fp,"%[^\n]%*1[\n]",buf));
            printf("%d\n",sscanf(buf,"%lf %lf %lf %lf %lf", &a, &b, &c, &d, &e));
            printf("%lf %lf %lf %lf %lf\n",a,b,c,d,e);
            printf("\n");
        }
    }
}