#include "lib/framework.hpp"


enum Size {
    WIDTH  = 800,
    HEIGHT = 600
};

int main() {
    AppEnv env(Size::WIDTH, Size::HEIGHT);

	Vec2f pos(0, -250);
	Vec2f v(0, 0);
	bool isCollision = false;

	while (env.isOpen()) {
		env.begin();

		Vec2f a(0, 0);


		if (pos.y() < 0) {
			if (env.isKeyPushed(' ')) {
				a += Vec2f(0, 10);
			}
			a += Vec2f(0, 0.2F);
		}
		if (pos.y() > 0) {
			if (env.isKeyPushed(' ')) {
				a += Vec2f(0, -10);
			}
			a += Vec2f(0, -0.2F);
		}


		if (env.isKeyPressing('A')) {
			a += Vec2f(-0.5F, 0);
		}
		if (env.isKeyPressing('D')) {
			a += Vec2f(0.5F, 0);
		}
		a += v * -0.05F;

		v += a;
		pos += v + 0.5F * a;

		drawPoint(pos.x(), pos.y(), 16, Color(0, 1, 0));

		if (pos.y() < HEIGHT / -2) {
			pos.y() = HEIGHT / -2;
			v.y() = 0;
		}
		if (pos.y() > HEIGHT / 2) {
			pos.y() = HEIGHT / 2;
			v.y() = 0;
		}
		if (pos.x() < WIDTH / -2) {
			pos.x() = WIDTH / -2;
			v.x() = 0;
		}
		if (pos.x() > WIDTH / 2) {
			pos.x() = WIDTH / 2;
			v.x() = 0;
		}

        env.end();
    }
}
