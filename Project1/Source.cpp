# include "iGraphics.h"
#include <stdio.h>
/*
function iDraw() is called again and again by the system.
*/
int ballposition_x = 192, ballposition_y = 16, ballderection = 1, randomnumber;
int s_p_x = 144, s_p_y = 0;
int ballmidpoint;
bool showBrick1 = true, showBrick2 = true, showBrick3 = true, showBrick4 = true, showBrick5 = true, showBrick6 = true, showBrick7 = true, showBrick8 = true, showBrick9 = true, showBrick10 = true,showBrick11=true;
int s= 0,score =0,end=0;
char lomat[30];
void ballmovement(){
	if (ballposition_y <= -32){
		end=5;
	}
	else if (ballposition_y >= 580&& ballderection<=610){
		ballmidpoint = ballposition_x + 16;
		if (showBrick1 == true && ballmidpoint > 368 && ballmidpoint < 440) {
			showBrick1 = false;
			ballderection=4;
			score++;
		}
	}
	else if (ballposition_y >= 520&& ballposition_y<=550){
		ballmidpoint = ballposition_x + 16;
		if (showBrick2 == true && ballmidpoint > 368 && ballmidpoint < 440){
			showBrick2 = false;
			ballderection=3;
		    score++;
		}
	}
	else if (ballposition_y >= 460&& ballposition_y<=490){
		ballmidpoint = ballposition_x + 16;
		if (showBrick3 == true && ballmidpoint > 368 && ballmidpoint < 440){
			showBrick3 = false;
			ballderection=4;
			score++;
		}
	}
	else if (ballposition_y >= 550&& ballposition_y<=580){
		ballmidpoint = ballposition_x + 16;
	    if (showBrick5 == true && ballmidpoint > 296 && ballmidpoint < 368){
		showBrick5 = false;
		ballderection=4;
		score++;
		}
	    else if (showBrick8 == true && ballmidpoint > 368 && ballmidpoint < 440){
		showBrick8 = false;
		ballderection=3;
		score=score+10;
		}
		else if (showBrick4 == true && ballmidpoint > 440 && ballmidpoint < 512){
			showBrick4 = false;
			ballderection=4;
			score++;
		}
		
	
	}
	else if (ballposition_y >= 490&& ballposition_y<=520){
		ballmidpoint = ballposition_x + 16;
		if (showBrick6 == true && ballmidpoint > 296 && ballmidpoint < 368){
			showBrick6 = false;
			ballderection=3;
			score++;
		}
		else if (showBrick9 == true && ballmidpoint > 368 && ballmidpoint < 440){
			showBrick9 = false;
			ballderection=4;
			score++;
		}
		else if (showBrick7 == true && ballmidpoint >440 && ballmidpoint <512){
			showBrick7 = false;
			ballderection=4;
			score=score+10;
		}
		/*else if (showBrick10 == true && ballmidpoint >224 && ballmidpoint < 296)
			showBrick10 = false;
		else if (showBrick11 == true && ballmidpoint >512 && ballmidpoint < 584)
			showBrick11 = false;*/
	}
	/*else if (showBrick2==true && ballmidpoint >= 296 && ballmidpoint <368)
			showBrick2 = false;
		else if (showBrick3==true && ballmidpoint >= 224 && ballmidpoint <296)
			showBrick3 = false;
		else if (showBrick4 == true && ballmidpoint >= 440 && ballmidpoint <512)
			showBrick4 = false;
		else if (showBrick5 == true && ballmidpoint >= 512 && ballmidpoint <584)
			showBrick5 = false;
	}*/
		if (ballposition_y == 16){
		ballmidpoint = ballposition_x + 16;
		if (ballmidpoint >= s_p_x - 10 && ballmidpoint <= s_p_x + 24){
			ballderection = 1;
		}
		else if (ballmidpoint >= s_p_x + 72 && ballmidpoint <= s_p_x + 106){
			ballderection = 2;
		}
		else if (ballmidpoint > s_p_x + 24 && ballmidpoint < s_p_x + 72){
			ballderection = 5;

		}
	}
	if (ballposition_x <= 0){
		if (ballderection == 1){
			ballderection = 2;
		}
		else if (ballderection == 3){
			ballderection = 4;
		}
	}
	else if (ballposition_x >=780){
		if (ballderection == 2){
			ballderection = 1;
		}
		else if (ballderection == 4){
			ballderection = 3;
		}
	}
	else if (ballposition_y >= 580){
		randomnumber = rand() % 3 + 1;
		if (randomnumber == 1){
			ballderection = 3;
		}
		else if (randomnumber == 2){
			ballderection = 4;
		}
		else
			ballderection = 6;

	}


	if (ballderection == 1){
		ballposition_x -= 4;
		ballposition_y += 4;
	}
	else if (ballderection == 2){
		ballposition_x += 4;
		ballposition_y += 4;
	}
	else if (ballderection == 3){
		ballposition_x -= 4;
		ballposition_y -= 4;
	}
	else if (ballderection == 4){
		ballposition_x += 4;
		ballposition_y -= 4;
	}
	else if (ballderection == 5){
		ballposition_y += 4;
	}
	else if (ballderection == 6){
		ballposition_y -= 4;
	}


}


void iDraw()
{
	iClear();
	if(end==5){
		iText(300,350,"GAME OVER",GLUT_BITMAP_TIMES_ROMAN_24);


	}


	iText(0,10,"score",GLUT_BITMAP_TIMES_ROMAN_24);
	itoa(score,lomat,10);
	iText(60,10,lomat,GLUT_BITMAP_TIMES_ROMAN_24);
	//iShowBMP (ball_x ,ball_y,"dxball.bmp");
	//iSetColor(0, 500, 500);
	//iFilledCircle(ballposition_x, ballposition_y, 15);
	//iShowBMP(0, 0, "0.bmp");
	iShowBMP(ballposition_x, ballposition_y, "ball1.bmp");
	iSetColor(128,128,128);
	iFilledRectangle(s_p_x, s_p_y, 96, 16);
	iSetColor(0, 128, 192);
	if (showBrick1 == true){
		iFilledRectangle(368, 580, 72, 30);
	}
	if (showBrick2 == true){
		iFilledRectangle(368, 520, 72, 30);
	}
	if (showBrick3 == true){
		iFilledRectangle(368, 460, 72, 30);
	}
	if (showBrick4 == true){
		iFilledRectangle(440, 550, 72, 30);
	}
	if (showBrick5 == true){
		iFilledRectangle(296, 550, 72, 30);
	}
	if (showBrick6 == true)
		iFilledRectangle(296, 490, 72, 30);
	if (showBrick7 == true)
		iFilledRectangle(440, 490, 72, 30);
	/*if (showBrick10 == true)
		iFilledRectangle(224, 490, 72, 30);
	if (showBrick11 == true)
		iFilledRectangle(512, 490, 72, 30);*/
	iSetColor(255, 255, 128);
	if (showBrick8 == true)
		iFilledRectangle(368,550, 72, 30);
	if (showBrick9 == true)
		iFilledRectangle(368, 490, 72, 30);

}
/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if (key == 'q')
	{
		//do something with 'q'
	}
	//place your codes for other keys here
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_LEFT && s_p_x >= 0){
		s_p_x -= 10;
	}
	else if (key == GLUT_KEY_RIGHT && s_p_x <= 700){
		s_p_x += 10;
	}

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
}

int main()
{
	//place your own initialization codes here. 
	iSetTimer(5, ballmovement);
	srand(time(NULL));
	iInitialize(800,600, "Dx Ball");
	PlaySound("bground",NULL,SND_LOOP | SND_ASYNC);
	return 0;
}