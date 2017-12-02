#include "lib/framework.hpp"


enum Size {
  WIDTH  = 512,
  HEIGHT = 512
};

int main() {
  AppEnv env(Size::WIDTH, Size::HEIGHT);


  Texture title("res/title_bg.png");
  Texture bgimage("res/game_bg.png");
  Texture fly("res/miku.png");
  Texture flyHit("res/miku_hit.png");
  Texture tataki("res/haetataki_1.png");
  Texture tataki2("res/haetataki_2.png");
  Texture point("res/miku_point.png");
  Texture clickstart("res/click_to_start.png");
  Texture logo("res/logo.png");

  Media taataakii("res/title.wav");
  Media start("res/start.wav");
  Media ide("res/hit.wav");
  Media end("res/end.wav");

  Random rand;
  int flyx, flyy;
  float t_interval = 1;
  float nextInterval = 0;
  int g_time = 0;

  int c = 0;

  taataakii.looping(false);
  taataakii.play();
  start.looping(false);
  ide.looping(false);
  end.looping(false);
  float r = 0;
  float s = 0;
  while (env.isOpen()) {
    env.begin();
	r += 0.1F;
	s += 0.05F;
	drawTextureBox(-WIDTH/2, -HEIGHT/2, 512, 512, 0, 0, 512, 512, title);
	drawTextureBox(-WIDTH / 2, (-HEIGHT / 2+50)+std::abs(std::sin(r))*10, 512, 128, 0, 0, 512, 128, clickstart);
	drawTextureBox(-WIDTH / 2, (-HEIGHT / 2)+std::sin(s)*20, 512, 512, 0, 0, 512, 512, logo);
	if (env.isButtonPushed(Mouse::LEFT)) {
		taataakii.stop();
		start.looping(false);
		start.play();
		flyx = rand(-WIDTH/2,WIDTH/4);
		flyy = rand(-HEIGHT / 2+64, HEIGHT/4);
		nextInterval = t_interval;
		break;
	}
    env.end();
  }

  bool isClicked = false;
  float hitInterval = 0.2F;

  while (env.isOpen()) {
	  env.begin();
	  Vec2f pos = env.mousePosition();
	  g_time += 1;
	  if (g_time > 60 * 15)
		  break;
	  nextInterval -= 0.01;
	  if (nextInterval < 0) {
		  flyx = rand(-WIDTH/2, WIDTH/4);
		  flyy = rand(-HEIGHT / 2+64, HEIGHT/4);
		  t_interval -= 0.05F;
		  if (t_interval < 0.3) {
			  t_interval = 0.3;
		  }
		  nextInterval = t_interval;
	  }

	  if (pos.x() < flyx + 128 && pos.x() > flyx
		  && pos.y() < flyy + 128 && pos.y() > flyy) 
	  {
		  if (env.isButtonPushed(Mouse::LEFT)) {
			  isClicked = true;
			  c++;
		  }
	  }

	  drawTextureBox(-WIDTH / 2, -HEIGHT / 2, 512, 512, 0, 0, 512, 512, bgimage);
	  
	  for (int i = 0; i < c; i++) {
		  drawTextureBox(-WIDTH / 2+(i*15), -HEIGHT / 2+10, 64, 64, 0, 0, 80, 80, point);
	  }
	  if (isClicked) {
		  ide.play();
		  int a = rand(-1, 1) * 3;
		  drawTextureBox(flyx+a, flyy+a, 150, 150, 0, 0, 256, 256, flyHit, Color(1, 0, 0));
		  hitInterval -= 0.01F;
		  if (hitInterval < 0) {
			  nextInterval = 0;
			  hitInterval = 0.1;
			  isClicked = false;
		  }
	  }else { drawTextureBox(flyx, flyy, 150, 150, 0, 0, 256, 256, fly); }

	  if (env.isButtonPushed(Mouse::LEFT)) {
		  drawTextureBox(pos.x() - 210, pos.y() - 230, 256, 256, 0, 0, 256, 256, tataki2);
	  }
	  else {
		  drawTextureBox(pos.x() - 210, pos.y() - 230, 256, 256, 0, 0, 256, 256, tataki);
	  }
	  env.end();
  }
  Texture bg_result("res/result.png");
  end.play();
  float t = 0;
  while (env.isOpen()) {
	  env.begin();
	  t += 0.2F;
	  drawTextureBox(-WIDTH / 2, -HEIGHT / 2, 512, 512, 0, 0, 512, 512, title);
	  for (int i = 0; i < c; i++) {
		  drawTextureBox(-WIDTH / 2 + (i * 15), -HEIGHT / 2 + 10, 64, 64, 0, 0, 80, 80, point);
	  }
	  drawTextureBox(-WIDTH / 2, -HEIGHT / 2, 512, 512, 0, 0, 512, 512, bg_result,Color(std::sin(t),rand(0,1),1));
	  env.end();
  }

}