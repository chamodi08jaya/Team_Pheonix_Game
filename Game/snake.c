#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "game.c"


//#include "SDL.h"
#include <stdlib.h>
#include <iostream>
/*int system(const char *command);*/
/*#include <stdlib.h>
#include "SDL.h"*/
//#include <gtk/gtk.h>

/*extern crate msgbox;

use msgbox::IconType;*/
	

#define COLUMNS 40
#define ROWS 40
#define FPS 10

extern short sDirection;
bool gameOver=false;

int score=0;

void timer(int){
	glutPostRedisplay();
	glutTimerFunc(1000/FPS,timer,0);
}


void keyboard(int key,int,int){
	switch(key){
		case GLUT_KEY_UP:
			if(sDirection!=DOWN)
				sDirection=UP;
			break;
		case GLUT_KEY_DOWN:
			if(sDirection!=UP)
				sDirection=DOWN;
			break;
		case GLUT_KEY_RIGHT:
			if(sDirection!=LEFT)
				sDirection=RIGHT;
			break;
		case GLUT_KEY_LEFT:
			if(sDirection!=RIGHT)
				sDirection=LEFT;
			break;
	}		

}

int index=0;
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	
	drawGrid();
	/*glRectd(index,20,index+2,22);
	index++;
	if(index>40){
		index=0;
	}*/
	drawSnake();
	drawFood();
	glutSwapBuffers(); 

	/*while (gameOver) {
    	int ret = system("foo");
    	if (WIFSIGNALED(ret) &&
        (WTERMSIG(ret) == SIGINT || WTERMSIG(ret) == SIGQUIT))
            break;
	}*/

	
	
    	//msgbox::create("Hello Title", "Hello World!", IconType::INFO);



	if(gameOver){

		char _score[10];
		/*itoa(score,_score,10);
		char text[50]="Your score:";
		strcat(text,_score);*/
		//int SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING,"Your Score:","GAME OVER",NULL);
		//MessageBox(NULL,text,"GAME OVER",0);
		
		exit(0);
	}


}

void reshape(int w,int h){
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
}

void init(){
	glClearColor(0.0,0.0,0.0,1.0);
	initGrid(COLUMNS,ROWS);

}

int main(int argc,char** argv){
	glutInit(&argc, argv);
    	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);    
    	glutInitWindowSize(500,500);        
    	glutInitWindowPosition(1,1);    
    	glutCreateWindow("Snake Game"); 
	glutCreateWindow("Snake Game2"); 
    	glutDisplayFunc(display); 
	glutReshapeFunc(reshape); 
	glutTimerFunc(0,timer,0); 
	glutSpecialFunc(keyboard);         
    	init();
    	glutMainLoop(); 
    	return 0;
}


