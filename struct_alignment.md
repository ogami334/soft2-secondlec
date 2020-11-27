# プログラムの説明
プログラムで表示したアドレスを基に数えると、各変数が占める領域はそれぞれ、
##student型構造体

id     int         4

name   char[100] 100

**age    int         8**

height double      8

weight double      8


##tagged_student1型構造体

id     int         4

name   char[100] 100

**age    int         8**

height double      8

weight double      8

**char   tag         8**


##tagged_student2型構造体

**tag    char        4**

id     int         4         

name   char[100] 100

age    int         4

height double      8

weight double      8

以下は、マークダウンの書き方のサンプル。全て消してください。そのあと、プログラムの説明を書いて下さい。


## Markdownの書き方解説
- markdownはただのテキストファイルです。それを、表示するプログラムが綺麗に表示してくれます。
- repl.itの場合は、マークダウンファイルをクリックしたうえで、編集画面の右上の「Edit」を押すと編集モードに、「Preview」を押すとレンダリングモードになります。
- vscodeの場合は、同じく編集画面右上の「Open Preview to the Slide」のアイコンを押すとレンダリングされます。
- GitHubのウェブからみると自動的にレンダリングされます

## 見出し

ああああ。
一回改行しても改行しない

いいい。二度改行すると改行する

太字は**こうする**と太字にある

- リストはこのようにする
- yyy
- zzz