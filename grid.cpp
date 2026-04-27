#include "constants.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "raylib.h"
#include "grid.h"


Grid::Grid(){
    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            grid[i][j]=empty_cell();  
        }
    }
}

cell Grid::empty_cell(){
    cell x; x.id=0; x.dir=0; x.updated=false;
    return x;
}

cell Grid::new_cell(int id){
    cell x; x.id=id;; x.updated=false;
    if (rand()%100 > 49) { x.dir = -1;}
    else {x.dir = 1;}
    return x;
}

void Grid::set_update_false(){
    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            grid[i][j].updated=false;  
        }
    }
}

void Grid::update_sand(int x,int y){
    int targetX = x + grid[y][x].dir;

    if(y!=HEIGHT-1 && (grid[y+1][x].id==0 || grid[y+1][x].id==2)){//falling

        grid[y][x].updated=true;
        grid[y+1][x].updated=true;
        cell tmp = grid[y+1][x];
        grid[y+1][x]=grid[y][x];
        grid[y][x]=tmp;

    }else if(y!=HEIGHT-1 && in_range(targetX) && (grid[y+1][targetX].id==0 || grid[y+1][targetX].id==2)){//pilling
        
        grid[y][x].updated=true;
        grid[y+1][targetX].updated=true;
        cell tmp = grid[y+1][targetX];
        grid[y+1][targetX]=grid[y][x];
        grid[y][x]=tmp;

    }else {

        grid[y][x].updated=true; 
        grid[y][x].dir *= -1;

    }
}

void Grid::update_water(int x,int y){
    int targetX = x + grid[y][x].dir;

    if(y!=HEIGHT-1 && grid[y+1][x].id==0){//falling

        grid[y][x].updated=true;
        grid[y+1][x].updated=true;
        cell tmp = grid[y+1][x];
        grid[y+1][x]=grid[y][x];
        grid[y][x]=tmp;

    } 
    if(in_range(targetX) && grid[y][targetX].id==0){//going sideways
        
        grid[y][x].updated=true;
        grid[y][targetX].updated=true;
        cell tmp = grid[y][targetX];
        grid[y][targetX]=grid[y][x];
        grid[y][x]=tmp;

    }else {

        grid[y][x].updated=true; 
        grid[y][x].dir *= -1;

    }
}

bool Grid::in_range(int index){
    if (index < 0 || index >= WIDTH) {
        return false;            
    }
    return true;
}

void Grid::draw(){
    ClearBackground(BLACK);

    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            if(grid[i][j].id==1){
                DrawRectangle(j*CELL_SIZE,i*CELL_SIZE,CELL_SIZE,CELL_SIZE,YELLOW);
            }
            else if(grid[i][j].id==2){
                DrawRectangle(j*CELL_SIZE,i*CELL_SIZE,CELL_SIZE,CELL_SIZE,DARKBLUE);
            }
        }
    }
}

void Grid::update_grid(){

    set_update_false();

    for(int i=HEIGHT-1;i>0;i--){
        for(int j=0;j<WIDTH;j++){
            //check if updated
            if(grid[i][j].updated){continue;}
            
            if(grid[i][j].id==1){//sand
                update_sand(j,i);
            }else if (grid[i][j].id==2){//water
                update_water(j,i);
            }
        }
    }
}

cell Grid::get(int x, int y){
    return grid[y][x];
}

void Grid::set(int x, int y, int id){
    grid[y][x] = new_cell(id);
}


