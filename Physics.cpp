#include "lib/framework.hpp"

enum Size {
    WIDTH  = 600,
    HEIGHT = 800
};

int main() {
    AppEnv env(Size::WIDTH, Size::HEIGHT);

	Vec2f pos(0, 350);
	Vec2f v(0, 0);     //初速度
	//Vec2f a(0, -0.25F);   //加速度


    while (env.isOpen()) {
        env.begin();

		Vec2f a(0, 0);     //
		if (env.isKeyPushed(' ')) {
			a += Vec2f(0, 10);
		}
		if (env.isKeyPushed('D')) {
			a += Vec2f(10, 0);
		}
		if (env.isKeyPushed('A')) {
			a -= Vec2f(10, 0);
		}
		a += Vec2f(0, -0.25);      //重力

		v += a;
		pos += v + 0.5F * a;

		drawPoint(pos.x(), pos.y(), 16, Color(1, 0, 0));

		if (pos.x() < -250 || pos.x() > 250) {
			v.x() = -v.x();
		}

		if (pos.y() < -350) {
			//v.y() = -v.y();
			v.y() = 0;
			pos.y() = -350;
		}

        env.end();
    }
}
