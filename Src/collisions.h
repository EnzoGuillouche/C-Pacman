#pragma once

#include <SDL.h>
#include "player.h"
#include "maze.h"

#define COLLISION_THRESHOLD 3
#define WALL_BOUNDARIES 3

bool CheckCollisionLeft(Player* player, Maze* maze) {
    return player->x_pos*PIXEL_SIZE > maze->x_pos*PIXEL_SIZE + WALL_BOUNDARIES*PIXEL_SIZE + COLLISION_THRESHOLD*PIXEL_SIZE;
}

bool CheckCollisionRight(Player* player, Maze* maze) {
    return player->x_pos*PIXEL_SIZE + PLAYER_SPRITE_WIDTH*PIXEL_SIZE + WALL_BOUNDARIES*PIXEL_SIZE < maze->x_pos*PIXEL_SIZE + MAZE_SPRITE_WIDTH*PIXEL_SIZE - COLLISION_THRESHOLD*PIXEL_SIZE;
}

bool CheckCollisionUp(Player* player, Maze* maze) {
    return player->y_pos*PIXEL_SIZE > maze->y_pos*PIXEL_SIZE + WALL_BOUNDARIES*PIXEL_SIZE + COLLISION_THRESHOLD*PIXEL_SIZE;
}

bool CheckCollisionDown(Player* player, Maze* maze) {
    return player->y_pos*PIXEL_SIZE + PLAYER_SPRITE_HEIGHT*PIXEL_SIZE + WALL_BOUNDARIES*PIXEL_SIZE < maze->y_pos*PIXEL_SIZE + MAZE_SPRITE_HEIGHT*PIXEL_SIZE - COLLISION_THRESHOLD*PIXEL_SIZE;
}

bool CheckCollisions(Player* player, Maze* maze) {
    if (player->x_velocity > 0) {
        // Moving right
        return CheckCollisionRight(player, maze);
    } else if (player->x_velocity < 0) {
        // Moving left
        return CheckCollisionLeft(player, maze);
    } else if (player->y_velocity > 0) {
        // Moving down
        return CheckCollisionDown(player, maze);
    } else if (player->y_velocity < 0) {
        // Moving up
        return CheckCollisionUp(player, maze);
    }
    return false; // No movement
}