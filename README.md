# #Nproject

Ⅰ)各自担当のフォルダの中だけを編集してください。
ex)タイトル担当の人はtitleフォルダの中だけをいじる

Ⅱ)フォルダと同名の関数がメイン関数のような扱いになります。
ex)titleフォルダであればtitle関数

Ⅲ)文字の出力の仕方などはhttp://dxlib.o.oo7.jp/dxfunc.htmlを参考に

Ⅳ)画像が描けたらimageフォルダに入れて、filename.datに上から名前を書いてください。

ⅴ)グローバル変数は"絶対"使わないこと。どうしても使いたかったら言ってください

Ⅵ)以下宣言しといたもの

変数
SCREEN_WIDTH  :スクリーンの横の大きさ
SCREEN_HEIGHT :スクリーンの縦の大きさ
scene         :現在の状態(タイトル画面であれば*scene=Title)

関数
長方形とマウスの当たり判定を行う関数(使うときはcollision.hをinclude)
int collision_rect(int x, int y, int width, int height, int pointX, int pointY);
x:長方形の左上x座標
y:長方形の左上y座標
width:長方形の横の大きさ
height:長方形の縦の大きさ
pointX:マウスのx座標
pointY:マウスのy座標
返り値:接触時:1,非接触時:0


aaaaaaaaaaaaaaaaaaa
