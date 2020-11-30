[wikipediaのこのページ](https://ja.wikipedia.org/wiki/データ構造アライメント#データ構造パティング)の記述を参考に書きました。

# student型構造体

id     int         4

name   char[100] 100

**age    int         8**　次の変数heightの手前までのサイズが8の倍数になるように4バイト分パディングしている.

height double      8

weight double      8




# tagged_student1型構造体

id     int         4

name   char[100] 100

**age    int         8** 次の変数heightの手前までのサイズが8の倍数になるように4バイト分パディングしている.

height double      8

weight double      8

**tag  char         8**　
全体のサイズが、8(この構造体の中の変数の中での最大バイト数)の倍数になるように7バイト分パディングしている。




# tagged_student2型構造体

**tag    char        4**　次の変数idの手前までのサイズが4の倍数になるように3バイト分パディングしている。

id     int         4         

name   char[100] 100

age    int         4

height double      8

weight double      8
