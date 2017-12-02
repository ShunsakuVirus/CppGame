//
// たくさん出す
//

// Frameworkの全てをインクルード
#include "lib/framework.hpp"
#include <ctime> // C++標準ライブラリの時計を使用


// アプリのウインドウサイズ
enum Size {
	WIDTH = 800,
	HEIGHT = 800
};

//
// メインプログラム
//
int main() {
	// アプリウインドウを生成
	// GLFWとOpenGLの初期化
	// TIPS:色々な型が依存しているので、最初に生成する事
	AppEnv env(Size::WIDTH, Size::HEIGHT);
	Random random;
	random.setSeed(std::time(nullptr));
	//int a = random(200); ======= 0~199
	//int a = random(-200, 200); =========== -200~200
	//float a = random(); ======== 0.0 ~ 1.0
	//float a = random(-2.8f, 3.2f); ======= -2.8~3.2
	int xDic;
	int yDic;
	int x[5];
	int y[5];
	int r[5];
	float c[5][3];
	for (int i = 0; i < 5; i++) {
		x[i] = random(-300, 300);
		y[i] = random(-300, 300);
		r[i] = random(10, 30);
		for (int a = 0; a < 3; a++) {
			c[i][a] = random(0.0f, 1.0f);
		}
	}
	//int x[10] = { 100, -200, 50, -80, 90, -90, 150, 120, -130, 220 };
	//int y[10] = { 5, 200, -356, 194, -300, -20, 50, 102, 367, -300 };
	//int r[10] = { 10, 50, 100, 150, 200, 30, 60, 250, 39, 120 };
	//float c[10][3]{ { 1, 0.5, 0.6 }, { 0.3, 0.7, 1 }, { 1, 0.8, 1 }, { 0.1, 0.9, 1 }, { 0.3, 1, 0 }, { 1, 1, 0.5 }, { 0.5, 1, 0.5 }, { 0, 0, 1 }, { 0.5, 0.5, 0.5 }, { 0.4, 0.1, 1 } };
	while (env.isOpen()) {
		// 開始
		env.begin();
		for (int i = 0; i < 5; i++)
		{
			drawPoint(x[i], y[i], r[i], Color(c[i][0], c[i][1], c[i][2]));
			//drawPoint(x[i], y[i], r[i], Color(c[i][0], c[i][1], c[i][2]);
			yDic = random(1, 5);
			xDic = random(1, 10);
				x[i] += xDic;
				y[i] += yDic;
				if (x[i] > WIDTH / 2 || x[i] < WIDTH / -2) { xDic *= -1; }
				if (y[i] > HEIGHT / 2 || y[i] < HEIGHT / -2) { yDic *= -1; }
			// 終了
		}
	env.end();
	}
}
