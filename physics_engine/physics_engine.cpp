#include <raylib.h>
int main() {
//creating game window
	int ballx = 400;
	int bally = 400;
	//initWindow(width is pixels, height, window name)
	InitWindow(800, 800, "Eiman and Aima's mighty simulation");
	
	SetTargetFPS(60); //takes in an integer
	//Update game loop 60 times per sec, ensures same speed for all
	// if we dont define fps, computer will try to run it as fast as possible
	
	//Game loop
	while (WindowShouldClose()==false) {
		//if escape key is pressed or close icon on window is clicked
		//it returns true and game loop ends

		//1. Event handling
		if (IsKeyDown(KEY_UP)) {
			bally -= 3; //decreases y coordinate of ball by 3 pixels every frame
		}

		//2. Updating position
		ballx += 3; //increases x coordinate of ball by 3 pixels every frame

		//3. Drawing
		BeginDrawing();
		 
		//clears screen with specified color to prevent overlapping drawings
		ClearBackground(LIGHTGRAY);

		//drawing a circle: x position, y position, radius, color
		DrawCircle(ballx, bally, 20, PINK);

		EndDrawing();
	}

	CloseWindow(); //need to close every created window
	return 0;
}