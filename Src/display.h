#pragma once

#include <SDL.h>

#include "sprite.h"

SDL_Rect pixel;
Uint32 color;
#define PIXEL_SIZE 2

SDL_Window* CreateWindow(const char* title, int width, int height) {
    return SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
}


void FillViewPort(SDL_Surface *psurface, Uint32 color) {
    SDL_FillRect(psurface, NULL, color);
}

void ClearViewPort(SDL_Surface *psurface) {
    FillViewPort(psurface, 0x000000);
}

void PlacePixelOnViewport(SDL_Surface *psurface, int x, int y, Uint32 color) {
    pixel = (SDL_Rect){ x*PIXEL_SIZE,y*PIXEL_SIZE,PIXEL_SIZE,PIXEL_SIZE };
    SDL_FillRect(psurface, &pixel, color);
}

void PlaceSpriteOnViewport(SDL_Surface *psurface, const char* psprite, int x, int y, int height, int width) {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            color = GetColorFromSprite(psprite, (width*row)+col);
            if (color != 0x000000) { // we don't draw transparent
                PlacePixelOnViewport(psurface, x + col, y + row, color);
            }
            
        }
    }
}

void DisplayViewport(SDL_Window *pwindow) {
    SDL_UpdateWindowSurface(pwindow);
}