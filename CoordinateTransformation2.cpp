#include "lib/framework.hpp"

void drawEdge(int i,Vec2f d[]) {
	drawLine(d[i].x(), d[i].y(), d[(i + 1) % 4].x(), d[(i + 1) % 4].y(), 1, Color(1, 1, 1));
}

enum Size {
  WIDTH  = 800,
  HEIGHT = 600
};

int main() {

  AppEnv env(Size::WIDTH, Size::HEIGHT);

  Vec2f vertex[4] = { Vec2f(-200,200),
					 Vec2f(200,200), 
					 Vec2f(200,-200), 
					 Vec2f(-200,-200) };

  float r = 0;
  int stateCount = 0;

  float a, b, c, d;

  while (env.isOpen()) {
    env.begin();

	Vec2f mouse = env.mousePosition();

	if (env.isButtonPushed(Mouse::LEFT)) {
		stateCount++;
	}

	if (stateCount % 3 == 0) {
		a = mouse.x()*0.01F;
		b = -std::sin(r);
		c = std::sin(r);
		d = mouse.y()*0.0F;
	}
	else if (stateCount % 3 == 1) {
		a = mouse.x()*0.01F;
		b = 0;
		c = 0;
		d = mouse.x()*0.01F;
	} 
	else {
		a = std::cos(r);
		b = -std::sin(r);
		c = std::sin(r);
		d = std::cos(r);
	}

	float s = mouse.x();
	float t = mouse.y();

	Vec2f dp[4];
	for (int i = 0; i < 4; i++) {
		dp[i].x() = vertex[i].x() * a + vertex[i].y() * b + s;
		dp[i].y() = vertex[i].x() * c + vertex[i].y() * d + t;
		drawPoint(dp[i].x(), dp[i].y(), 16, Color(1, a, b));
		drawEdge(i,dp);
	}
	r += 0.01F;

    env.end();
  }
}
