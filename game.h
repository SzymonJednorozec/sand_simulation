#pragma once
#include "constants.h"
#include "grid.h"

class Game
{
private:
    Grid grid;
public:
    Game();

    void mouse_input();

    void grid_update();

    void draw();
    
};

