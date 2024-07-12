#include <iostream>
#include <raylib.h> /// Raylib is a library for making games

using namespace std;

class Ball
{
public:
    float x, y;
    int speed_x, speed_y;
    int radius;

    void Draw()
    {
        DrawCircle(x, y, radius, WHITE);
    }

    // function to move the ball
    void move()
    {
        x += speed_x;
        y += speed_y;

        if (y+radius>=GetScreenHeight() || y-radius<=0) { // checking if the ball touch the bottom or top of the screen
        speed_y*=-1; //changing the direction of the ball in y direction


        if (x+radius>=GetScreenWidth() || x-radius<=0) { // for left and right side obstruction
            speed_x*=-1
        }
            
        }
    }
};

Ball ball;

int main()
{
    cout << "Starting the game" << endl;
    const int screenWidth = 1280;
    const int screenHeight = 720;
    InitWindow(screenWidth, screenHeight, "Ping Pong");

    SetTargetFPS(60); // this function will set the frame rate of the game to 60 frames per second
    // if we didn't set the frame rate the game will run as fast as the computer can handle

    ball.radius = 20;
    ball.x = screenWidth / 2;
    ball.y = screenHeight / 2;
    ball.speed_x = 7;
    ball.speed_y = 7;

    while (WindowShouldClose() == false)
    {                   // the game will run until window function get false value either from windows close or esc key
        BeginDrawing(); // this function creates a blankcanvas so that we can starting drawinng

ClearBackground(BLACK); // this function will clear the background of the canvas and set it to black

        ball.move();
        // remember that the coordinate system in raylib starts from the top left corner of the screen updown :y side: x

        DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE); // x1 y1 x2 y2 color

        ball.Draw();
       
        DrawRectangle(12, screenHeight / 2 - 60, 25, 120, WHITE); // x y width height color

        DrawRectangle(screenWidth - 37, screenHeight / 2 - 60, 25, 120, WHITE);
 

        EndDrawing(); // this function will end the drawing and display the canva
    }

    CloseWindow();
    return 0;
}
