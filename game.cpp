#include "constants.h"
#include "game.h"
#include "raylib.h"

Game::Game(){
    
}

void Game::mouse_input(){
    if(IsMouseButtonDown(0)){
        int x = GetMouseX();
        int y = GetMouseY();

        x = x/CELL_SIZE;
        y = y/CELL_SIZE;
        
        grid.set(x,y,1);

    }
    if(IsMouseButtonDown(1)){
        int x = GetMouseX();
        int y = GetMouseY();

        x = x/CELL_SIZE;
        y = y/CELL_SIZE;
        
        grid.set(x,y,2);
    }
}

void Game::grid_update(){
    grid.update_grid();
}

void Game::draw(){
    grid.draw();
}