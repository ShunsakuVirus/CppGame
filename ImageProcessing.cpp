//
// アプリ雛形
//
// VisualStudioでもコンパイルできるようにするため
// ソースコードをUTF-8(BOM付き)で用意:D
//

// Frameworkの全てをインクルード
#include "lib/framework.hpp"


// アプリのウインドウサイズ
enum Size {
  WIDTH  = 512 * 2,
  HEIGHT = 600
};

//
// メインプログラム
//
int main() {
  // アプリウインドウを生成
  // GLFWとOpenGLの初期化
  // TIPS:色々な型が依存しているので、最初に生成する事
  AppEnv env(Size::WIDTH, Size::HEIGHT);

  Texture image("res/miku.png");
  Texture image2("res/AI_Nomal.png");

  while (env.isOpen()) {
    // 開始
    env.begin();

	Vec2f pos = env.mousePosition();
	drawTextureBox(-512, -256,  //表示XY
					512, 512,   //表示サイズ
					pos.x(), pos.y(),     //切り取り位置XY
					pos.x(), pos.y(),   //切り取りサイズ
					image);   
	drawTextureBox(0, -256, 512, 512, pos.x(), pos.x(), pos.y(), pos.y(), image2);
    //
    // ここにアプリの処理を書く
    //
    
    // 終了
    env.end();
  }
}
