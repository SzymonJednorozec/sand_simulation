#include "constants.h"
#include "game.h"
#include "raylib.h"
#include <cstdlib>
#include <ctime>
#include <iostream>


int main() {
    srand(time(0));
    Game game;

    InitWindow(WIDTH*CELL_SIZE, HEIGHT*CELL_SIZE, "sand_simulation");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        game.mouse_input();
        game.grid_update();
        game.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}