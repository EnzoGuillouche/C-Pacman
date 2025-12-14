#pragma once

#include <SDL.h>

Uint8 r,g,b;
SDL_Rect pixel;
int pixel_x = 50;
int pixel_y = 50;


SDL_Window* CreateWindow(const char* title, int width, int height) {
    return SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
}

void UpdateViewport(SDL_Surface *psurface, int x, int y, Uint8 r, Uint8 g, Uint8 b) {
    pixel = (SDL_Rect){ x,y,1,1 };
    Uint32 color = SDL_MapRGB(psurface->format, r, g, b);
    SDL_FillRect(psurface, &pixel, color);
}

void DisplayViewport(SDL_Window *pwindow) {
    SDL_UpdateWindowSurface(pwindow);
}