#include <stdio.h>
#include <stdbool.h>

#include "display.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(void)
{
    SDL_Window* pwindow = CreateWindow("PacSDL", SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_Surface* psurface = SDL_GetWindowSurface(pwindow);

    int x_pos = 100;
    int y_pos = 100;

    bool running = true;
    while (running)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE))
            {
                running = false;
                break;
            }

            // Input handling
            // .......... c:
        }

        // Display
        ClearViewPort(psurface);

        x_pos += 1;
        if (x_pos > SCREEN_WIDTH) x_pos = 0;

        const char* psprite = LoadSprite("Bin/test_sprite.txt", 0);
        if (psprite) {
            PlaceSpriteOnViewport(psurface, psprite, x_pos, y_pos);
            free((void*)psprite);
        }

        DisplayViewport(pwindow);
    }

    // clean up resources before exiting.
    SDL_DestroyWindow(pwindow);
    SDL_Quit();
}