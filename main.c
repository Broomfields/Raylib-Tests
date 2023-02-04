#include "raylib.h"

int main() 
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Ya Boi Rendering like a digital Bob Ross");

    Camera camera = { 0 };
    camera.position = (Vector3){ 10.0f, 10.0f, 8.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    
    SetCameraMode(camera, CAMERA_ORBITAL);

    // Vector3 cubePosition = { 0 };
    float startX = 100;
    float startY = 100;
    float endX = 500;
    float endY = 250;

    float adj = 0;
    float adjColour = 230;

    float thick = 12;
    float fontSize = 20;
    Color colour = RAYWHITE;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        Color red = (Color){ adjColour, 41, 55, 255 };    // Red
        Color green = (Color){ 0, adjColour, 48, 255 };   // Green
        Color blue = (Color){ 0, 121, adjColour, 255 };     // Blue

        if (adjColour < 250)
        {
            adjColour++;
        }
        else if (adjColour < 5)
        {
            adjColour--;
        }


        if (startX > 500)
        {
            adj = -1;
        }
        else if (startX < 100)
        {
            adj = 1;
        }

        // Update
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(DARKGRAY);
            
            // BeginMode3D(camera);
            // DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
            // DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
            // DrawGrid(10, 1.0f);
            // EndMode3D();

            DrawLineBezier((Vector2){startX, startY}, (Vector2){endX, endY}, thick, red);
            DrawLineBezierQuad((Vector2){startX, startY}, (Vector2){endX, endY}, (Vector2){endX - startX, endY - startY}, thick, green);
            DrawLineBezierCubic((Vector2){startX, startY}, (Vector2){endX, endY}, (Vector2){endX - startX, endY - startY}, (Vector2){endY - startY, endX - startX}, thick, blue);
           
            // DrawLineBezier((Vector2){startX, endY}, (Vector2){endX, startY}, thick, colour);
            // DrawLineBezierQuad((Vector2){startX, endY}, (Vector2){endX, startY}, (Vector2){endX - startX, endY - startY}, thick, colour);
            // DrawLineBezierCubic((Vector2){startX, endY}, (Vector2){endX, startY}, (Vector2){endX - startX, endY - startY}, (Vector2){endY - startY, endX - startX}, thick, colour);

            DrawText("Origin", startX, startY - (fontSize * 1.5), fontSize, colour);

            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------

        startX += adj;
        startY += (adj / 2);

    
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}