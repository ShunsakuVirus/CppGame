#include "lib/framework.hpp"
enum Size {
  WIDTH  = 800,
  HEIGHT = 600
};

int main() {
  AppEnv env(Size::WIDTH, Size::HEIGHT);

  while (env.isOpen()) {
    env.begin();

	drawLine(0, 0, -150, 200, 1, Color(0, 1, 0));

	Vec2f pos = env.mousePosition();
	drawLine(0, 0, pos.x(), pos.y(), 1, Color(0, 1, 0));
	float dot = -150 * pos.x() + 200 * pos.y();
	float cross = -150 * pos.y() - pos.x() * 200;
	//if (dot < 0) drawLine(0, 0, pos.x(), pos.y(), 1, Color(1, 0, 0));
	if (cross < 0) drawLine(0, 0, pos.x(), pos.y(), 1, Color(0, 0, 1));
	printf("%d", cross);
    env.end();
  }
}
