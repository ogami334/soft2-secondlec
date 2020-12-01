//二次元化する
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
//#include "physics3.h"

// シミュレーション条件を格納する構造体
// 反発係数CORを追加
typedef struct condition
{
  const int width; // 見えている範囲の幅
  const int height; // 見えている範囲の高さ
  const double G; // 重力定数
  const double dt; // シミュレーションの時間幅
  const double corx; // x方向の壁の反発係数
  const double cory; // y方向の壁の反発係数
} Condition;

// 個々の物体を表す構造体
typedef struct object
{
  double m;
  double x;
  double y;
  double prev_x;
  double prev_y; // 壁からの反発に使用
  double vx;
  double vy;
} Object;

// 授業で用意した関数のプロトタイプ宣言

void plot_objects(Object objs[], const size_t numobj, const double t, const Condition cond);
void update_velocities(Object objs[], const size_t numobj, const Condition cond);
void update_positions(Object objs[], const size_t numobj, const Condition cond);
void bounce(Object objs[], const size_t numobj, const Condition cond);

// To do: 以下に上記と同じ引数で実行される my_* を作成
// 実装できたらmain関数で上記と入れ替えていく
// my_plot_objects(), my_update_velocities(), my_update_positions(), my_bounce の4つ 
void my_update_velocities_and_positions(Object objs[], const size_t numobj, const Condition cond) {
  double accels[numobj][2];
  for (int i=0;i<numobj;i++) {
    for (int j=0;j<2;j++) {
        accels[i][j]=0;        
    }
  } //j=0がx
  for (int i=0;i<numobj;i++) {
    objs[i].prev_y=objs[i].y;
    objs[i].prev_x=objs[i].x;
  }
  for (int i=0;i<numobj;i++) {
    for (int j=0;j<numobj;j++) {
      if (i==j) {
        continue;
      }
      accels[i][0]+=(cond.G)*(objs[j].m)/pow(pow(objs[j].y-objs[i].y,2)+pow(objs[j].x-objs[i].x,2),1.5)*(objs[j].x-objs[i].x);
      accels[i][1]+=(cond.G)*(objs[j].m)/pow(pow(objs[j].y-objs[i].y,2)+pow(objs[j].x-objs[i].x,2),1.5)*(objs[j].y-objs[i].y);
    }
  }//位置を更新する前に加速度を出しておく
  for (int i=0;i<numobj;i++) {
    objs[i].x=objs[i].x+objs[i].vx * cond.dt;
    objs[i].y=objs[i].y+objs[i].vy * cond.dt;
  } //速度を更新する前に位置を更新する
  for (int i=0;i<numobj;i++) {
    objs[i].vx =objs[i].vx + accels[i][0] * cond.dt;
    objs[i].vy =objs[i].vy + accels[i][1] * cond.dt;
  } //最後に速度を更新
}
//void my_update_positions(Object objs[], const size_t numobj, const Condition cond);


void my_plot_objects(Object objs[], const size_t numobj, const double t, const Condition cond) {
  int map[cond.height][cond.width];
  for (int i=0;i<cond.height;i++) {
    for (int j=0;j<cond.width;j++) {
      map[i][j]=0;
    }
  }
  for (int i=0;i<numobj;i++) {
    if ((-cond.height <= 2*objs[i].y) && (2*objs[i].y <=cond.height) && (-cond.width <= 2*objs[i].x) && (2*objs[i].x <= cond.width)) {
      map[(int) (objs[i].y + cond.height/2)][(int) (objs[i].x + cond.width/2)]=1;
    }
  }
  for (int i=0;i<cond.width+2;i++) {
    printf("-");
  } //上の壁
  printf("\n");
  for (int i=0;i<cond.height;i++) {
    printf("|");
    for (int j=0;j<cond.width;j++) {
      if (map[i][j]==1) {
        printf("o");
      }
      else {
        printf(" ");
      }
    }
    printf("|\n");
  }
  for (int i=0;i<cond.width+2;i++) {
    printf("-");
  } //下の壁
  printf("\n");
  printf("t = %.1lf ",t);
  for (int i=0;i<numobj;i++) {
    printf("objs[%d].x = %.2lf ",i,objs[i].x);
    printf("objs[%d].y = %.2lf ",i,objs[i].y);
  }
  printf("\n");
  
}

void my_bounce(Object objs[], const size_t numobj, const Condition cond) {
  for (int i=0;i<numobj;i++) {
    if (objs[i].prev_y < cond.height/2 && objs[i].y > cond.height/2) {
      objs[i].vy *= -(cond.cory);
      objs[i].y = cond.height -objs[i].y;
    }
    else if (objs[i].prev_y > -cond.height/2 && objs[i].y < -cond.height/2) {
      objs[i].vy *= -(cond.cory);
      objs[i].y = -cond.height - objs[i].y;
    }
    if (objs[i].prev_x < cond.width/2 && objs[i].x > cond.width/2) {
      objs[i].vx*= -(cond.corx);
      objs[i].x = cond.width -objs[i].x;
    }
    else if (objs[i].prev_x > -cond.width/2 && objs[i].x < -cond.width/2) {
      objs[i].vx *= -(cond.corx);
      objs[i].x = -cond.width - objs[i].x;
    }

  }
} //衝突に関してはひとまず、衝突せずに動いた場合の壁からの距離を折り返し、速度を(-e)倍にするという実装にしている
//速度がとても大きいとバグの原因になりそう


int main(int argc, char **argv){
  const Condition cond = {
		    .width  = 75,
		    .height = 40,
		    .G = 1.0,
		    .dt = 1.0,
		    .corx = 0.2,
        .cory = 0.8
  };//これは変えなくて良さそう
  
  size_t objnum = 2;
  Object objects[objnum];
  if ( argc != 2 ) {
    fprintf(stderr, "usage: %s [filename for init]\n", argv[0]);
    return EXIT_FAILURE;
  }  
  else {
    FILE *fp;
    int flag=1;
    int cnt=0;
    if ((fp =fopen(argv[1],"r"))!=NULL) {
      while (flag==1) {
        if (fgetc(fp)=='#') {
          char trash[100];
          fscanf(fp,"%[^\n]*1[\n]",trash);
        }
        else {
          double a,b,c,d,e;
          char buf[100];
          int item=fscanf(fp,"%lf %lf %lf %lf %lf%[^\n]*1[\n]",&a,&b,&c,&d,&e,buf);
          if (item>0 && cnt<objnum) {
            objects[cnt].m=a;
            objects[cnt].x=b;
            objects[cnt].y=c;
            objects[cnt].vx=d;
            objects[cnt].vy=e;
            cnt+=1;
          }
          else {
            flag=0;
          }
        }
      }
      if (objnum>cnt+1) {
        for (int i=0;i<objnum-cnt-1;i++) {
          objects[cnt].m=0;
          objects[cnt].x=-1000;
          objects[cnt].y=-1000;
          objects[cnt].vx=0;
          objects[cnt].vy=0;
        }
      }
    }
  }

  // objects[1] は巨大な物体を画面外に... 地球のようなものを想定
  /*objects[0] = (Object){ .m = 60.0, .x = 3.0, .y = -19.9, .vx = -4.0, .vy = 2.0};
  objects[1] = (Object){ .m = 100000.0, .x =0.1, .y =  1000.0, .vx =0, .vy = 0.0};
  objects[2] = (Object){ .m = 60.0, .x = -3.0, .y = -19.9, .vx =3.0, .vy =1.5};*/

  // シミュレーション. ループは整数で回しつつ、実数時間も更新する
  const double stop_time = 400;
  double t = 0;
  printf("\n");
  for (int i = 0 ; t <= stop_time ; i++){
    t = i * cond.dt;
    //update_velocities(objects, objnum, cond);
    //update_positions(objects, objnum, cond);
    my_update_velocities_and_positions(objects,objnum,cond);

    //bounce(objects, objnum, cond);
    my_bounce(objects, objnum, cond);
    
    // 表示の座標系は width/2, height/2 のピクセル位置が原点となるようにする
    my_plot_objects(objects, objnum, t, cond);
    
    usleep(200 * 1000); // 200 x 1000us = 200 ms ずつ停止
    printf("\e[%dA", cond.height+3);// 壁とパラメータ表示分で3行
  }
  return EXIT_SUCCESS;
}

// 実習: 以下に my_ で始まる関数を実装する
// 最終的に phisics2.h 内の事前に用意された関数プロトタイプをコメントアウト

