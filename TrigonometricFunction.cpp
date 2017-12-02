#include "lib/framework.hpp"
enum Size {
  WIDTH  = 800,
  HEIGHT = 600
};
int main() {
  AppEnv env(Size::WIDTH, Size::HEIGHT);
  float angle = 0.0F;

  while (env.isOpen()) {
    env.begin();

	Vec2f pos = env.mousePosition();

	angle += 0.1F;
	float x = pos.x() + (std::cos(angle));
	float y = pos.y() + (std::sin(angle));
	float c = std::abs(std::sin(angle));

	// a = ++i;  aが1
	// a = i++;  aが0
	//drawFillBox(x, y, 32, 32, Color(c, c, c));
	/*for (int i = 0; i < 100; i++) {
		float r = angle + i * 0.05;
		float x = std::cos(r) * 200.0F;
		float y = std::sin(r * 0.7F) * 150.0F;

		float c = i / 100.0F;
		drawFillBox(x, y, 32, 32, Color(c, c, c));
	}*/
	drawFillBox(pos.x() + (c * 120), pos.y() + (c * 120), 64, 64, Color(1, 1, 1));
	drawFillBox(pos.x() - (c * 120), pos.y() + (c * 120), 64, 64, Color(1, 1, 1));
	drawFillBox(pos.x() + (c * 120), pos.y() - (c * 120), 64, 64, Color(1, 1, 1));
	drawFillBox(pos.x() - (c * 120), pos.y() - (c * 120), 64, 64, Color(1, 1, 1));
	drawFillBox(pos.x() + (c * 220), pos.y() + (c * 220), 64, 64, Color(1, c, c));
	drawFillBox(pos.x() - (c * 220), pos.y() + (c * 220), 64, 64, Color(c, c, c));
	drawFillBox(pos.x() + (c * 220), pos.y() - (c * 220), 64, 64, Color(c, 1, 1));
	drawFillBox(pos.x() - (c * 220), pos.y() - (c * 220), 64, 64, Color(1, 1, c));

	drawFillBox(pos.x(), pos.y() + (c * 120), 64, 64, Color(1, 1, 1));
	drawFillBox(pos.x(), pos.y() + (c * 220), 64, 64, Color(1, c, 1));
	drawFillBox(pos.x() + (c * 120), pos.y(), 64, 64, Color(1, 1, 1));
	drawFillBox(pos.x() + (c * 220), pos.y(), 64, 64, Color(1, c, c));
	drawFillBox(pos.x() - (c * 120), pos.y(), 64, 64, Color(1, 1, 1));
	drawFillBox(pos.x() - (c * 220), pos.y(), 64, 64, Color(c, 1, c));
	drawFillBox(pos.x(), pos.y() - (c * 120), 64, 64, Color(1, 1, 1));
	drawFillBox(pos.x(), pos.y() - (c * 220), 64, 64, Color(c, c, 1));

    env.end();
  }
}
