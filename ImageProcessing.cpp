#include "lib/framework.hpp"

enum Size {
  WIDTH  = 512 * 2,
  HEIGHT = 600
};
int main() {
  AppEnv env(Size::WIDTH, Size::HEIGHT);

  Texture image("res/miku.png");
  Texture image2("res/AI_Nomal.png");

  while (env.isOpen()) {
    env.begin();

	Vec2f pos = env.mousePosition();
	drawTextureBox(-512, -256,  //表示XY
					512, 512,   //表示サイズ
					pos.x(), pos.y(),     //切り取り位置XY
					pos.x(), pos.y(),   //切り取りサイズ
					image);   
	drawTextureBox(0, -256, 512, 512, pos.x(), pos.x(), pos.y(), pos.y(), image2);
    env.end();
  }
}
