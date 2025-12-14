#pragma once

#include <SDL.h>

#include "sprite.h"

SDL_Rect pixel;

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
    pixel = (SDL_Rect){ x,y,1,1 };
    SDL_FillRect(psurface, &pixel, color);
}

void DisplayViewport(SDL_Window *pwindow) {
    SDL_UpdateWindowSurface(pwindow);
}