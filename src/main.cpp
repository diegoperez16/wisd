#include "raylib.h"

int main()
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Walter in San Digo: It's hard to be alive");

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        // TODO: Add game logic here

        // Draw
        BeginDrawing();
        
        ClearBackground(RAYWHITE);
        
        DrawText("Walter in San Digo", 190, 200, 40, LIGHTGRAY);
        DrawText("Press ESC to exit", 270, 250, 20, GRAY);
        
        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
