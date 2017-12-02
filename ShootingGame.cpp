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
	
	Vec2f direction = Vec2f(0, 0);
	Vec2f player = Vec2f(0, 0);
	float speed = 0.1F;
	float time = 0.0F;
	bool isClicked = false;

	float x[100];     //弾の位置
	float y[100];
	float vx[100];    //弾の進む量
	float vy[100];
	int active[100];		 //弾の有無 boolでも化

	for (int i = 0; i < elemsof(active); i += 1) {
		x[i] = 0.0F;
		y[i] = 0.0F;
		vx[i] = 0.0F;
		vy[i] = 0.0F;
		active[i] = 0;
	}

    while (env.isOpen()) {
        // 開始
        env.begin();
		//自作↓
		//if (env.isButtonPushed(Mouse::LEFT)) {
		//	Vec2f mousePos = env.mousePosition();
		//	direction = Vec2f(mousePos.x() / 60, mousePos.y()/ 60);
		//	isClicked = true;
		//	//speed = 0.1F;
		//}
		//if (env.isButtonPushed(Mouse::RIGHT)) {
		//	Vec2f mousePos = env.mousePosition();
		//	direction = Vec2f(mousePos.x()/ 60, mousePos.y()/ 60);
		//	isClicked = true;
		//	//speed = 0.2F;
		//}
		//if (isClicked) {
		//	time = time + 1.0F / 60;
		//	if (time == 1) {
		//		isClicked = false;
		//		time = 0.0F;
		//	}
		//}
		//drawPoint(player.x(), player.y(), 10, Color(0, 1, 0));
		////player += direction * speed;
		//player += direction;


		if (env.isButtonPushed(Mouse::LEFT)) {
			for (int i = 0; i < elemsof(active); i += 1) {
				if (active[i] == 0) {  //配列に何も入っていないか（空かどうか）を確認
					active[i] = 1;	   //配列に1を入れる（空じゃなくする）
					Vec2f pos = env.mousePosition();
					float dx = pos.x() - player.x();
					float dy = pos.y() - player.y();
					float length = std::sqrt(dx * dx + dy * dy);
					vx[i] = (dx / length) * 5;
					vy[i] = (dy / length) * 5;
					x[i] = player.x();
					y[i] = player.y();
					break;
				}
			}
		}

		/*x += vx;
		y += vy;*/

		//移動
		for (int i = 0; i < elemsof(active); i += 1) {
			if (active[i] == 1) {
				x[i] += vx[i];
				y[i] += vy[i];
				if (x[i] > WIDTH / 2 || x[i] < WIDTH / -2) {
					vx[i] *= -1;
				}
				if (y[i] > HEIGHT / 2 || y[i] < HEIGHT / -2) {
					vy[i] *= -1;
				}
				float diameter = 10;
				float radius = diameter / 2;
				float aP = player.x() - x[i];
				float bP = player.y() - y[i];
				float distP = std::sqrt(aP * aP + bP * bP);
				if (distP <= radius) {
					printf("%s", "gameover");
				}
				for (int j = 0; j < elemsof(active); j += 1) {
					if (i != j && active[j]) {
						float a = x[i] - x[j];
						float b = y[i] - y[j];
						float dist = std::sqrt(a * a + b * b);
						if (dist <= radius) {
							active[i] = 0;
							active[j] = 0;
						}
					}
				}
			}
		}

		//弾
		for (int i = 0; i < elemsof(active); i += 1) {
			if (active[i] == 1) {
				drawPoint(x[i], y[i], 10, Color(0, 1, 0));
			}
		}

		if (env.isKeyPressing('D') || env.isKeyPressing(KEY_RIGHT)) {
			player.x() += 1;
		}
		if (env.isKeyPressing('A') || env.isKeyPressing(KEY_LEFT)) {
			player.x() -= 1;
		}
		if (env.isKeyPressing('W') || env.isKeyPressing(KEY_UP)) {
			player.y() += 1;
		}
		if (env.isKeyPressing('S') || env.isKeyPressing(KEY_DOWN)) {
			player.y() -= 1;
		}

		//zero 座標に弾を撃つプレイヤーがいる
		drawPoint(player.x(), player.y(), 10, Color(1, 1, 1));


        env.end();
    }
}
