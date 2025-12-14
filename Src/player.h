#pragma once

#include <SDL.h>

typedef struct Player {
    int x_pos;
    int y_pos;
    int x_velocity;
    int y_velocity;
} Player;

void GoToDirection(Player* player, int x_velocity, int y_velocity) {
    player->x_velocity = x_velocity;
    player->y_velocity = y_velocity;
}

void MovePlayer(Player* player) {
    player->x_pos += player->x_velocity;
    player->y_pos += player->y_velocity;
}