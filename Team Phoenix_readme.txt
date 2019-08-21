# Project Title
Implementing a Snake game using Open GL and C++ as a part of Graphic and Visualisation subject in second year first semester.

#Technology used
C++ language and Open GL

#How to play the game 
Used arrow keys to move snake here and there.
Up arrow key-going upwards
Down arrow key-going downwards
Left arrow key-going left side
Right arrow key-going right side

Scores will be given for the number of foods eaten by snake.

Snake's length will be increased due to number of foods eaten by snake.But Snake length will only limited for the 50 square size.

Game overs , When the snake hits on the wall,and when the snake's head  hits on it's body.

There are 2 buttons.They are Retry and Cancel button. When click on the Retry button the game will start on beginning with the storing previous high score.
 At this time the score will remove. But the High score will save. 
If we click on the Cancel button the game will exit while removing previous Scores and high score. 
 
#Installation for Ubuntu
Perform installation of Open GL , freeglut etc.
apt-get install freeglut3-dev 

#Running the game
     In Ubuntu,
	Compile the game:
		g++  Game.cpp  -o  main.o -lglut -lGLU -lGL -lm 

	Run the game: 
		./main.o 

     In Windows,
	Compile the game:
		F9

	Run the game: 
		F10
		

Made by [Team Phoenix ]( https://github.com/chamodi08jaya/Team_Pheonix_Game.git)

Last updated: 21st of August 2019.
