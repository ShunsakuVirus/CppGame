#include "lib/framework.hpp"

enum Size {
  WIDTH  = 800,
  HEIGHT = 600
};

int main() {
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
