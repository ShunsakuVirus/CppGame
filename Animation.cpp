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
  WIDTH  = 800,
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
  int count = 0;

  while (env.isOpen()) {
	env.begin();
	count++;
	Vec2f pos = env.mousePosition();
	//int pattern = ((count / 8) % 3) + 1;
	int p[7] = { 5, 6, 7, 3, 4, 3, 4 };
	int pattern = p[(count / 8) % 7];
	int x = (pattern % 3) * 320;
	int y = (pattern / 3) * 270;
	//count++;
	drawTextureBox(pos.x() - 320 / 2, pos.y() - 270 / 2, 320, 270, x, y, 320, 270, image);
    env.end();
  }
}