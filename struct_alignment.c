#include <stdio.h>

struct student
{
  int id;
  char name[100];
  int age;
  double height;
  double weight;
};

struct tagged_student1
{
  int id;
  char name[100];
  int age;
  double height;
  double weight;
  char tag;
};

struct tagged_student2
{
  char tag;
  int id;
  char name[100];
  int age;
  double height;
  double weight;
};

int main (int argc, char**argv)
{
  struct student s_begin;
  struct student s1;
  struct tagged_student1 s2;
  struct tagged_student2 s3;
  struct tagged_student2 s_end;

  /* 以下に各構造体の中身のポインタを表示するプログラムを書く */
  /* printf で %p フォーマットを指定する*/
  /* 逆順に表示（send, s3, s2, s1, sbegin の順）*/
  printf("s_end\n");
  printf("%p\n",&s_end.tag);
  printf("%p\n",&s_end.id);
  printf("%p\n",&s_end.name);
  printf("%p\n",&s_end.age);
  printf("%p\n",&s_end.height);
  printf("%p\n",&s_end.weight);
  printf("s3\n");
  printf("%p\n",&s3.tag);
  printf("%p\n",&s3.id);
  printf("%p\n",&s3.name);
  printf("%p\n",&s3.age);
  printf("%p\n",&s3.height);
  printf("%p\n",&s3.weight);
  printf("s2\n");
  printf("%p\n",&s2.id);
  printf("%p\n",&s2.name);
  printf("%p\n",&s2.age);
  printf("%p\n",&s2.height);
  printf("%p\n",&s2.weight);
  printf("%p\n",&s2.tag);
  printf("s1\n");
  printf("%p\n",&s1.id);
  printf("%p\n",&s1.name);
  printf("%p\n",&s1.age);
  printf("%p\n",&s1.height);
  printf("%p\n",&s1.weight);
  printf("s_begin\n");
  printf("%p\n",&s_begin.id);
  printf("%p\n",&s_begin.name);
  printf("%p\n",&s_begin.age);
  printf("%p\n",&s_begin.height);
  printf("%p\n",&s_begin.weight);
  printf("\n");



  // do_something!!

  /* 以下には各構造体のサイズをsizeof演算子で計算し、表示する */
  long size_send = sizeof s_end;
  long size_s3 = sizeof s3;
  long size_s2 = sizeof s2; 
  long size_s1 = sizeof s1; 
  long size_sbegin = sizeof s_begin;       
  /* printf 表示には%ld を用いる*/
  printf("構造体のサイズ\n");
  printf("s_end   %ld\n",size_send);
  printf("s3      %ld\n", size_s3);
  printf("s2      %ld\n",size_s2);
  printf("s1      %ld\n",size_s1);
  printf("sbegin  %ld\n",size_sbegin);



  // do_something!!
  
  return 0;
}
