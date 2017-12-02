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

  float x[4];
  float y[4];
  float squareX[4] = { 100, 100, -100, -100 };
  float squareY[4] = { 100, -100, -100, 100 };
  float sqColor[4][3] = { {0, 1, 1}, {1, 0, 0}, {0, 1, 0}, {1, 0, 1} };
  for (int i = 0; i < elemsof(x); i += 1) {
	  x[i] = squareX[i];
	  y[i] = squareY[i];
  }
  float r = 0.0F;

  while (env.isOpen()) {
    // 開始
    env.begin();

	Vec2f mousePos = env.mousePosition();

	r += 0.01F;

	/*float a = mousePos.x()*0.01F;
	float b = -std::sin(r);
	float c = std::sin(r);
	float d = mousePos.y()*0.0F;*/
	/*float a = mousePos.x()*0.01F;
	float b = 0;
	float c = 0;
	float d = mousePos.x()*0.01F;*/ // 拡大縮小

	float a = 1;
	float b = 0;
	float c = 0;
	float d = 1;
	float s = mousePos.x();
	float t = mousePos.y();
	float x1[4];
	float y1[4];
	for (int i = 0; i < elemsof(x); i += 1) {
		float x1[4];
		float y1[4];
		x1[i] = x[i] * a + y[i] * b + s;
		y1[i] = x[i] * c + y[i] * d + t;

		drawPoint(x1[i], y1[i], 16, Color(sqColor[i][0], sqColor[i][1], sqColor[i][2]));
		drawLine(x1[i], y1[i], x1[(i + 1) % elemsof(x)], y1[(i + 1) % elemsof(x)], 1, Color(1, 1, 1));
	}
    env.end();
  }
}



