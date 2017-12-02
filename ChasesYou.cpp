#include "lib/framework.hpp"


enum Size {
	WIDTH = 800,
	HEIGHT = 600
};

int main() {
	AppEnv env(Size::WIDTH, Size::HEIGHT);

	float r = 0.0F;
	float x = 0.0F;
	float y = 0.0F;

	while (env.isOpen()) {

		env.begin();

		Vec2f mpos = env.mousePosition();
		{
			//敵から自分へ伸びるベクトル
			float ax = mpos.x() - x;
			float ay = mpos.y() - y;

			float len = std::sqrt(ax *ax + ay*ay);
			ax = ax / len;
			ay = ay / len;

			//敵の正面方向へ伸びるベクトル
			float bx = 0;
			float by = 1;

			//敵の向きに合わせて回転
			float sin_t = std::sin(r);
			float cos_t = std::cos(r);

			float rbx = bx * cos_t - by * sin_t;
			float rby = bx * sin_t + by * cos_t;

			float dot = ax * rbx + ay * rby;

			//外積を計算
			float cross = ay * rbx - ax * rby;
			//外積の正負で向きを変える
			if (dot > 0.9) {
				if (cross > 0) {
					r += 0.1;
				}
				if (cross < 0) {
					r -= 0.1;
				}
				float vx = 
				/*x += ax * 2;
				y += ay * 2;*/

				/*x += -2*sin_t;
				y += 2*cos_t;*/
			}
		}

		float sin_t = std::sin(r);
		float cos_t = std::cos(r);

		float ex = 0.0F;
		float ey = 50.0F;

		float rex = ex * cos_t - ey * sin_t + x;
		float rey = ex * sin_t + ey * cos_t + y;

		drawLine(x, y, rex, rey, 2, Color(1, 1, 1));
		drawFillCircle(x, y, 20, 20, 20, Color(1, 1, 1));

		drawFillCircle(mpos.x(), mpos.y(), 20, 20, 20, Color(0, 1, 0));
		env.end();
	}
}
