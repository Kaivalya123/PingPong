#include <graphics.h>
#include <iostream>
using namespace std;

void PlayBox(int a, int b, int c, int d){
	rectangle(a, b, c, d);
}

void Slider1(int a, int b, int c, int d){
	rectangle(a, b, c, d); //Slider 1
}

void Slider2(int a, int b, int c, int d){
	rectangle(a, b, c, d); //Slider 2
}


int main() {

    int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

	char ch;

	//Setting values
	//x1, y1, x2, y2 are locations and s1, s2 are sliders
	int x1s1 = 20;
	int y1s1 = 280;
	int x2s1 = 35;
	int y2s1 = 380;
	int x1s2 = 1225;
	int y1s2 = 280;
	int x2s2 = 1240;
	int y2s2 = 380;

	//Co-ordinates of playing box
	int x1 = 1;
	int y1 = 1;
	int x2 = 1270;
	int y2 = 670;

	int score_s1 = 0;
	int score_s2 = 0;

	//Ball
	int xball = 630; //x
	int yball = 330; //y
	int vx = 10; //Velocity x
	int vy = 10; //Velocity y
	int vs1 = 0; //Velocity slider 1
	int vs2 = 0; //Velocity slider 2

	for(int i = 0; i>=0; i++){

		y1s1 = y1s1+vs1;
		y2s1 = y2s1+vs1;
		y1s2 = y1s2+vs2;
		y2s2 = y2s2+vs2;

		PlayBox(x1, y1, x2, y2); //Playing box
		Slider1(x1s1, y1s1, x2s1, y2s1); //Slider 1
		Slider2(x1s2, y1s2, x2s2, y2s2); //Slider 2

		circle(xball, yball, 10); //Ball
		xball = xball+vx; //It moves with velocity of 5 (x)
		yball = yball+vy; //It moves with velocity of 5 (y)

		delay(40);
		cleardevice();

		if(xball-10<15 || xball+10>=1250){ //If ball goes to boundary (x)
			vx = -vx; //Change direction (x)
		}

		if(yball-10<15 || yball+10>=650){ //If ball goes to boundary (y)
			vy = -vy; //Change direction (y)
		}

		if (kbhit()){

					ch = getch();

					if(int(ch) == 119){ //W key
						vs1 = -10;
					}


					if(int(ch) == 115){ //S key
						vs1 = 10;
					}

					if(int(ch) == 111){ //O key
						vs2 = -10;
					}

					if(int(ch) == 108){ //L key
						vs2 = 10;
					}
				}

				if(y1s1 <= 20){ //If slider 1 goes to the top boundary
					y1s1 = 20;
					y2s1 = 120;
					if(vs1 <= 0){
						vs1 = 0;
					}
				}

				if(y2s1 >= 640){ //If slider 1 goes to the bottom boundary
					y2s1 = 640;
					y1s1 = 540;
					if(vs1 >= 10){
						vs1 = 0;
					}
				}

				if(y1s2 <= 20){ //If slider 2 goes to the top boundary
					y1s2 = 20;
					y2s2 = 120;
					if(vs2 <= 0){
						vs2 = 0;
					}
				}


				if(y2s2 >= 640){ //If slider 2 goes to the bottom boundary
					y2s2 = 640;
					y1s2 = 540;
					if(vs2 >= 10){
						vs2 = 0;
					}
				}

				if(xball-15 <= x2s1 && yball >= y1s1 && yball <= y2s1 && xball-15 >= x1s1){ //Ball bouncing on slider 1
							vx = -vx;
							score_s1 = score_s1 + 1; //Score of slider 1 increases by 1
							if(score_s1 >= 10){ //If slider 1 score is 10
								cleardevice();
								settextstyle(10, 0, 5);
								outtextxy(450, 330, "Player 1 Wins!!!");
								break;
							}
				}

				if(xball+15 >= x1s2 && yball >= y1s2 && yball <= y2s2 && xball+15 <= x2s2){ //Ball bouncing on slider 2
							vx = -vx;
							score_s2 = score_s2 + 1; //Score of slider 2 increases by 1
							if(score_s2 >= 10){ //If slider 2 score is 10
								cleardevice();
								settextstyle(10, 0, 5);
								outtextxy(450, 330, "Player 2 Wins!!!");
								break;
							}
				}


				//Slider 1 top
				if(yball+10 >= y1s1 && xball >= x1s1-10 && xball <= x2s1+10){
					vy = -vy;
				}

				//Slider 2 top
				if(yball+10 >= y1s2 && xball >= x1s2-10 && xball <= x2s2+10){
					vy = -vy;
				}

				//Slider 1 down
				if(yball-10 >= y2s1 && xball >= x1s1-10 && xball <= x2s1+10){
					vy = -vy;
				}

				//Slider 2 down
				if(yball-10 >= y2s2 && xball >= x1s2-10 && xball <= x2s2+10){
					vy = -vy;
				}

				/*
				//Corner
				//Slider 1
				if(xball+10 <= x2s1 && yball+10 >= y1s2){
					vx = -vx;
					vy = -vy;
				}

				if(xball+10 <= x2s1 && yball+10 <= y2s1){
					vy = -vy;
					vx = -vy;
				}

				//Slider 2
				if(xball+10 >= x1s2 && yball+10 >= y1s2){
					vx = -vx;
					vy = -vy;
				}

				if(xball+10 >= x1s2 && yball+10 <= y2s2){
					vy = -vy;
					vx = -vy;
				}
				*/

				//Prints score of slider 1
				char str1[128];
				settextstyle(10, 0, 5);
				sprintf(str1, "%d", score_s1);
				outtextxy(320, 330, str1);

				//Prints score of slider 2
				char str2[128];
				settextstyle(10, 0, 5);
				sprintf(str2, "%d", score_s2);
				outtextxy(940, 330, str2);

				if(xball+10 >= x1s2 && yball >= y1s2-15 && yball <= y2s2+15){
					xball = x1s2-5;
				}

				if(xball-10 <= x1s1 && yball >=y1s1-15 && yball <= y2s1+15){
					xball = x1s1+5;
				}
	}

	getch();
	closegraph();

	return 0;
}
