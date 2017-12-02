#include "lib/framework.hpp"

enum Size {
  WIDTH  = 800,
  HEIGHT = 600
};

int main() {
  AppEnv env(Size::WIDTH, Size::HEIGHT);

  Vec2f posA;
  Vec2f posB;
  bool isClicked = false;

  while (env.isOpen()) {
    env.begin();
	Vec2f mousePos = env.mousePosition();

	if (env.isButtonReleased(Mouse::LEFT)) {
		isClicked = false;
		if (posA != posB) {
			float diffx = std::abs(posA.x() - posB.x());
			float diffy = std::abs(posA.y() - posB.y());
			float dist = std::sqrt(diffx*diffx + diffy*diffy);
		}
	}
	if (env.isButtonPushed(Mouse::LEFT)) {
		isClicked = true;
		posA.x() = mousePos.x();
		posA.y() = mousePos.y();
	}
	if (env.isButtonPressing(Mouse::LEFT) && isClicked) {
		// dragging
		posB.x() = mousePos.x();
		posB.y() = mousePos.y();
		drawLine(posA.x(), posA.y(), posB.x(), posB.y(), 3, Color(0, 1, 0));

		float arrowx = posB.x() - posA.x();
		float arrowy = posB.y() - posA.y();
		float arrowLength = std::sqrt(arrowx * arrowx + arrowy * arrowy);
		float arrowAngle = std::atan(arrowy / arrowx);
		float deriveLineLength = arrowLength/2;
		Vec2f posC;
		Vec2f posD;
		if (arrowx >= 0 && arrowy >= 0) {
			posC.x() = posA.x() + std::cos(arrowAngle + 0.7071F) * deriveLineLength;
			posC.y() = posA.y() + std::sin(arrowAngle + 0.7071F) * deriveLineLength;
			posD.x() = posA.x() + std::cos(arrowAngle - 0.7071F) * deriveLineLength;
			posD.y() = posA.y() + std::sin(arrowAngle - 0.7071F) * deriveLineLength;
		}
		else if (arrowx <= 0 && arrowy >= 0) {
			posC.x() = posA.x() - std::cos(arrowAngle + 0.7071F) * deriveLineLength;
			posC.y() = posA.y() - std::sin(arrowAngle + 0.7071F) * deriveLineLength;
			posD.x() = posA.x() - std::cos(arrowAngle - 0.7071F) * deriveLineLength;
			posD.y() = posA.y() - std::sin(arrowAngle - 0.7071F) * deriveLineLength;
		}
		else if (arrowx <= 0 && arrowy <= 0) {
			posC.x() = posA.x() - std::cos(arrowAngle + 0.7071F) * deriveLineLength;
			posC.y() = posA.y() - std::sin(arrowAngle + 0.7071F) * deriveLineLength;
			posD.x() = posA.x() - std::cos(arrowAngle - 0.7071F) * deriveLineLength;
			posD.y() = posA.y() - std::sin(arrowAngle - 0.7071F) * deriveLineLength;
		}
		else if (arrowx >= 0 && arrowy <= 0) {
			posC.x() = posA.x() + std::cos(arrowAngle + 0.7071F) * deriveLineLength;
			posC.y() = posA.y() + std::sin(arrowAngle + 0.7071F) * deriveLineLength;
			posD.x() = posA.x() + std::cos(arrowAngle - 0.7071F) * deriveLineLength;
			posD.y() = posA.y() + std::sin(arrowAngle - 0.7071F) * deriveLineLength;
		}

		drawLine(posA.x(), posA.y(), posC.x(), posC.y(), 3, Color(0, 0, 1));
		drawLine(posA.x(), posA.y(), posD.x(), posD.y(), 3, Color(1, 0, 0));
	}

    env.end();
  }
}
