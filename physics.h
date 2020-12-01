// シミュレーション条件を格納する構造体
typedef struct condition
{
  const int width; // 見えている範囲の幅
  const int height; // 見えている範囲の高さ
  const double G; // 重力定数
  const double dt; // シミュレーションの時間幅
} Condition;

// 個々の物体を表す構造体
typedef struct object
{
  double m;
  double y;
  double vy;
} Object;

// 授業で用意した関数のプロトタイプ宣言

void plot_objects(Object objs[], const size_t numobj, const double t, const Condition cond);
void update_velocities(Object objs[], const size_t numobj, const Condition cond);
void update_positions(Object objs[], const size_t numobj, const Condition cond);

// To do: 以下に上記と同じ引数で実行される my_* を作成
// 実装できたらmain関数で上記と入れ替えていく
// my_plot_objects(), my_update_velocities(), my_update_positions() の3つ 
void my_update_velocities_and_positions(Object objs[], const size_t numobj, const Condition cond) {
  double accels[numobj];
  for (int i=0;i<numobj;i++) {
    accels[i]=0;
  }
  for (int i=0;i<numobj;i++) {
    for (int j=0;j<numobj;j++) {
      if (i==j) {
        continue;
      }
      accels[i]+=(cond.G)*(objs[j].m)/pow(fabs(objs[j].y-objs[i].y),3)*(objs[j].y-objs[i].y);
    }
  }//位置を更新する前に加速度を出しておく
  for (int i=0;i<numobj;i++) {
    objs[i].y=objs[i].y+objs[i].vy * cond.dt;
  } //速度を更新する前に位置を更新する
  for (int i=0;i<numobj;i++) {
    objs[i].vy =objs[i].vy + accels[i] * cond.dt;
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
    if ((-cond.height <= 2*objs[i].y) && (2*objs[i].y <=cond.height)) {
      map[(int) (objs[i].y + cond.height/2)][cond.width- cond.width/2-1]=1;
    }
  }
  for (int i=0;i<cond.height;i++) {
    for (int j=0;j<cond.width;j++) {
      if (map[i][j]==1) {
        printf("o");
      }
      else {
        printf(" ");
      }
    }
    printf("\n");
  }
  printf("-----\n");
  printf("t = %.1lf ",t);
  for (int i=0;i<numobj;i++) {
    printf("objs[%d].y = %.2lf ",i,objs[i].y);
  }
  printf("\n");
  
}