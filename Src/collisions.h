#pragma once

#include <SDL.h>
#include "player.h"
#include "maze.h"

#define COLLISION_THRESHOLD 3
#define WALL_BOUNDARIES 3


bool CheckCollisionLeft(MazeBoundaries* maze_boundaries) {
    return strcmp(maze_boundaries->pboundaries[maze_boundaries->width * maze_boundaries->pacman_pos[1] + maze_boundaries->pacman_pos[0] - 1], "1") != 0;
}

bool CheckCollisionRight(MazeBoundaries* maze_boundaries) {
    return strcmp(maze_boundaries->pboundaries[maze_boundaries->width * maze_boundaries->pacman_pos[1] + maze_boundaries->pacman_pos[0] + 1], "1") != 0;
}

bool CheckCollisionUp(MazeBoundaries* maze_boundaries) {
    return strcmp(maze_boundaries->pboundaries[maze_boundaries->width * (maze_boundaries->pacman_pos[1]-1) + maze_boundaries->pacman_pos[0]], "1") != 0;
}

bool CheckCollisionDown(MazeBoundaries* maze_boundaries) {
    return strcmp(maze_boundaries->pboundaries[maze_boundaries->width * (maze_boundaries->pacman_pos[1]+1) + maze_boundaries->pacman_pos[0]], "1") != 0;
}

bool CheckCollisions(Player* player, MazeBoundaries* maze_boundaries) {
    
    if (player->x_velocity > 0) {
        // Moving right
        return CheckCollisionRight(maze_boundaries);
    }
    if (player->x_velocity < 0) {
        // Moving left
        return CheckCollisionLeft(maze_boundaries);
    } else if (player->y_velocity > 0) {
        // Moving down
        return CheckCollisionDown(maze_boundaries);
    } else if (player->y_velocity < 0) {
        // Moving up
        return CheckCollisionUp(maze_boundaries);
    }
    return false; // No movement
}