#include "lib/framework.hpp"

enum Size {
  WIDTH  = 800,
  HEIGHT = 600
};

int main() {
  AppEnv env(Size::WIDTH, Size::HEIGHT);

  float a = 0;
  while (env.isOpen()) {

    env.begin();

	Vec2f mousePos = env.mousePosition();
	Vec2f enemyPos;
	enemyPos.x() = 50;
	enemyPos.y() = 50;

	Vec2f enemyEndPos;
	if (env.isKeyPressing(KEY_RIGHT)) {
		a += 0.01F;
	}
	if (env.isKeyPressing(KEY_LEFT)) {
		a -= 0.01F;
	}
	enemyEndPos.x() = enemyPos.x() + std::sin(a) * 50;
	enemyEndPos.y() = enemyPos.y() + std::cos(a) * 50;

	Vec2f v1;
	Vec2f v2;
	v1.x() = enemyEndPos.x() + std::sin(a + 0.3907F) * 50;
	v1.y() = enemyEndPos.y() + std::cos(a + 0.9205F) * 50;
	v2.x() = enemyEndPos.x() + std::sin(a - 0.3907F) * 50;
	v2.y() = enemyEndPos.y() + std::cos(a - 0.9205F) * 50;

	/*float x = enemyEndPos.x()-enemyPos.x();
	float y = enemyEndPos.y()-enemyPos.y();*/
	float x = v1.x() - enemyPos.x();
	float y = v1.y() - enemyPos.y();
	float x1 = v2.x() - enemyPos.x();
	float y1 = v2.y() - enemyPos.y();
	float x2 = mousePos.x() - enemyPos.x();
	float y2 = mousePos.y() - enemyPos.y();
	float dot = x2 * x + y2 * y;
	float dot1 = x2 * x1 + y2 * y1;
	if (dot > 0 && dot1 > 0) {
		drawFillCircle(enemyPos.x(), enemyPos.y(), 30, 30, 36, Color(1, 0, 0));
	} else {
		drawFillCircle(enemyPos.x(), enemyPos.y(), 30, 30, 36, Color(1, 1, 1));
	}
	drawLine(enemyPos.x(), enemyPos.y(), enemyEndPos.x(), enemyEndPos.y(), 3, Color(1, 1, 1));
	drawFillCircle(mousePos.x(), mousePos.y(), 30, 30, 36, Color(0, 1, 0));
    env.end();
  }
}
