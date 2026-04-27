#pragma once
#include "constants.h"

struct cell {
    int id;
    int dir;
    bool updated;
};

class Grid {
private:
    cell grid[HEIGHT][WIDTH];

    cell empty_cell();

    cell new_cell(int id);

    void set_update_false();

    void update_sand(int x, int y);

    void update_water(int x, int y);

    bool in_range(int index);

public:
    Grid();

    void draw();

    void update_grid();

    cell get(int x, int y);

    void set(int x, int y, int id);
};