#include <raylib.h>
#include <iostream>
#include <cmath>
#include <vector> //using vectors to store all the balls
using namespace std;

//making a struct (can use class) to define a ball
struct ball {
	//position:
	int ballx;
	int bally;

	//velocity:
	int velx;
	int vely;

	//color:
	Color color;
	/* Color is defined in raylib 
	typedef struct Color {
	unsigned char r;  // Red (0-255)
	unsigned char g;  // Green (0-255)
	unsigned char b;  // Blue (0-255)
	unsigned char a;  // Alpha/transparency (0-255)
    } Color;
*/
};

int main() {
//creating game window

	vector<ball> balls; //a vector to store all balls

	//initWindow(width in pixels, height, window name)
	InitWindow(800, 800, "Eiman's Angry Escape");
	
	SetTargetFPS(60); //takes in an integer
	//Update game loop 60 times per sec, ensures same speed for all
	// if we dont define fps, computer will try to run it as fast as possible
	
	//Game loop
	while (WindowShouldClose()==false) {
		//if escape key is pressed or close icon on window is clicked
		//it returns true and game loop ends

		//1. Event handling
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) // built-in function (parameter)
		{
			ball newBall; //creating a new ball 
			newBall.ballx = GetMouseX(); //new ball will be created at mouse position
			newBall.bally = GetMouseY();

			//velocity of every new ball:
			newBall.velx = 0; // Don't want horizontal velocity rn
			newBall.vely = 3; //(setting it to be same temporarily)

			newBall.color = PINK; //setting same color for now

			//adding every new ball to the vector
			balls.push_back(newBall);
		}

		//2. Updating position
		
		// for all balls in the vector
		for (int i = 0; i < balls.size(); i++) {
			balls[i].ballx += balls[i].velx; //adding velocity of every ball to its current position 
			balls[i].bally += balls[i].vely;

			// 800- radius 20 = 780 = boundary
			if (balls[i].ballx >= 780 || balls[i].ballx <= 20){
				balls[i].velx *= -1; //reversing velocity for bouncing
			}

			if (balls[i].bally >= 780 || balls[i].bally <= 20) {
				balls[i].vely *= -1;
			}
		}

		//3. Drawing
		BeginDrawing();

		/* raylib built - in colors : LIGHTGRAY, GRAY, DARKGRAY, YELLOW, GOLD, ORANGE, PINK, RED, 
		                              MAROON, GREEN, LIME, DARKGREEN, SKYBLUE, BLUE, DARKBLUE, PURPLE, 
									  VIOLET, DARKPURPLE, BEIGE, BROWN, DARKBROWN, WHITE, BLACK, 
									  BLANK (transparent), MAGENTA, RAYWHITE (raylib custom) */

		// raylib custom color: Color myColor = { red, green, blue, alpha };  // Each value 0-255
		 
		//clears screen with specified color to prevent overlapping drawings
		ClearBackground(LIGHTGRAY);

		//drawing a circle: x position, y position, radius, color

		//for all balls in the vector
		for (int i = 0; i < balls.size(); i++) {
			DrawCircle(balls[i].ballx, balls[i].bally, 20, balls[i].color);
		}
		EndDrawing();
	}

	CloseWindow(); //need to close every created window
	return 0;
}