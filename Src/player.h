#pragma once

#include <SDL.h>

#include "display.h"
#include "sprite.h"

typedef struct Player {
    int x_pos;
    int y_pos;
    int x_velocity;
    int y_velocity;
    const char* psprite;
} Player;

void PlayerGoToDirection(Player* player, int x_velocity, int y_velocity) {
    player->x_velocity = x_velocity;
    player->y_velocity = y_velocity;
}

void PlayerMove(Player* player) {
    player->x_pos += player->x_velocity;
    player->y_pos += player->y_velocity;
}

void PlayerSetSprite(Player* player, int spriteIndex) {
    player->psprite = LoadSprite("Bin/Sprites/pacman.txt", PLAYER_SPRITE_HEIGHT, PLAYER_SPRITE_WIDTH, spriteIndex);   
}

void PlayerDisplay(Player* player, SDL_Surface* psurface) {
    PlaceSpriteOnViewport(psurface, player->psprite, player->x_pos, player->y_pos, PLAYER_SPRITE_HEIGHT, PLAYER_SPRITE_WIDTH);
}