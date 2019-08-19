#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <ctime>
#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#define COLUMNS 40
#define ROWS 40
#define FPS 10
#define MAX 60

#define UP  1
#define DOWN -1
#define RIGHT 2
#define LEFT -2

int snake_length=5;
int posX[60]={20,20,20,20,20},posY[60]={20,19,18,17,16};
bool food=true;
int foodX,foodY;
int gridX,gridY;
int score=0;
int highscore = 0;
char buffer[10];
bool gameOver=false;
short sDirection=RIGHT;

void initGrid(int x,int y){
	gridX=x;
	gridY=y;

}

void timer(int){
	glutPostRedisplay();
	glutTimerFunc(1000/FPS,timer,0);
}

void unit(int x,int y){
	if(x==0||y==0||x==gridX-1||y==gridY-1){
		glLineWidth(3.0);
		glColor3f(0.0,0.0,0.0);	
	}else{
		glLineWidth(1.0);
		glColor3f(0.0,0.0,0.0);
	}
	
	glBegin(GL_LINE_LOOP);
		glVertex2f(x,y);
		glVertex2f(x+1,y);
		glVertex2f(x+1,y+1);
		glVertex2f(x,y+1);
	glEnd();
}

void keyboard(int key,int,int){
	switch(key){
		case GLUT_KEY_UP:
			if(sDirection!=DOWN){
				sDirection=UP;
			}
			break;
		case GLUT_KEY_DOWN:
			if(sDirection!=UP){
				sDirection=DOWN;
			}
			break;
		case GLUT_KEY_RIGHT:
			if(sDirection!=LEFT){
				sDirection=RIGHT;
			}
			break;
		case GLUT_KEY_LEFT:
			if(sDirection!=RIGHT){
				sDirection=LEFT;
			}
			break;
	}		

}
void drawGrid(){
	for(int x=0;x<gridX;x++){
		for(int y=0;y<gridY;y++){
			unit(x,y);
		}
	}
}

void drawSnake(){
	for(int i=snake_length-1;i>0;i--){
		posX[i]=posX[i-1];
		posY[i]=posY[i-1];
		}
	if(sDirection==UP){
		posY[0]++;
	}else if(sDirection==DOWN){
		posY[0]--;
	}else if(sDirection==RIGHT){
		posX[0]++;
	}else if(sDirection==LEFT){
		posX[0]--;
	}
	for(int i=0;i<snake_length;i++){
		if(i==0){
			glColor3f(0.0,1.0,0.0);
		}else{
			glColor3f(0.0,0.0,1.0);
		}
		glRectd(posX[i],posY[i],posX[i]+1,posY[i]+1);
	}

	
	if(posX[0]==0||posX[0]==gridX-1||posY[0]==0||posY[0]==gridY-1){
		gameOver=true;
	}
	for (int i= snake_length-1;i>0;i--)
    {
        if (posX[0]==posX[i]&&posY[0]==posY[i]){ 
            gameOver=true; break;}
    }
    if (posX[0]==foodX && posY[0]== foodY)
    {
        score++;
        snake_length++;
        if (snake_length>MAX){
            snake_length= MAX;
        };
        food=true;
    }
}



void random(int &x,int &y){
	int _maxX=gridX-2;
	int _maxY=gridY-2;
	int _min=1;
	srand(time(NULL));
	x=_min+rand() % (_maxX-_min);
	y=_min+rand() % (_maxY-_min);
}
void reset()
{
    snake_length= 5;
    posX[0]=20;posX[1]=20;posX[2]=20;posX[3]=20;posX[4]=20;
    posY[0]=20;posY[1]=19;posY[2]=18;posY[3]=17;posY[4]=16;                   
    score = 0;
    gameOver=false;
}

void drawFood(){
	if(food){
		random(foodX,foodY);
	}
	food=false;
	glColor3f(1.0,0.0,0.0);
	glRectd(foodX,foodY,foodX+1,foodY+1);		
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	drawGrid();
	drawSnake();
	drawFood();
	
	if(score>highscore)
    {
         highscore = score;
    }
    glutSwapBuffers();

    if (gameOver==true)
    {
        char _score[10];
        char _hscore[10];
        itoa(score,_score,10);
        itoa(highscore,_hscore,10);
	    char text[50]= " The Score : ";
        char texth[50]="\n The highscore : ";
        strcat(text,_score);
        strcat(texth,_hscore);
        strcat(text,texth);
        int msgbox=MessageBoxA(NULL,text, " Game Over ",MB_RETRYCANCEL|MB_ICONINFORMATION);
        switch(msgbox){
            case IDRETRY:
                    reset();
                    break;
            case IDCANCEL:
                    exit(0);
                    break;
        }
    }
}

void menu(int value)
{

    switch (value)
    {
    case 1:
		reset();
        break;
    
    }
    glutPostRedisplay();
}
	
void init(){
	glClearColor(1.0,1.0,1.0,1.0);
	initGrid(COLUMNS,ROWS);

}

void reshape(int w,int h){
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
}
 
int main(int argc,char** argv){
	glutInit(&argc, argv);
    	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);    
    	glutInitWindowSize(500,500);        
    	glutInitWindowPosition(1,1);    
    	glutCreateWindow("Snake Game");  
    	glutCreateMenu(menu);
    	glutAddMenuEntry("score",1);
    	glutDisplayFunc(display); 
		glutReshapeFunc(reshape); 
		glutTimerFunc(0,timer,0); 
		glutSpecialFunc(keyboard);         
    	init();
    	glutMainLoop(); 
    	return 0;
}


