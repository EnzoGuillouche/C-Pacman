#pragma once

#include <SDL.h>

#include "display.h"
#include "sprite.h"

typedef struct maze_boundaries {
    char* pboundaries;
    int width;
    int height;
    int ppacman_pos[2];
} MazeBoundaries;

typedef struct maze {
    int x_pos;
    int y_pos;
    const char* psprite;
} Maze;

void MazeSetSprite(Maze* maze) {
    maze->psprite = LoadSprite("Bin/Sprites/maze.txt", MAZE_SPRITE_HEIGHT, MAZE_SPRITE_WIDTH, 0);   
}

void MazeDisplay(Maze* maze, SDL_Surface* psurface) {
    PlaceSpriteOnViewport(psurface, maze->psprite, maze->x_pos, maze->y_pos, MAZE_SPRITE_HEIGHT, MAZE_SPRITE_WIDTH);
}