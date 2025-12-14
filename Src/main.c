#include <stdio.h>
#include <stdbool.h>

#include "display.h"

int main(void)
{
    SDL_Window* pwindow = CreateWindow("PacSDL", 800, 600);
    SDL_Surface* psurface = SDL_GetWindowSurface(pwindow);

    bool running = true;
    while (running)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE))
            {
                running = false;
                break;
            }

            // PlacePixelOnViewport(psurface, 50, 50, 0xFF0000);

            ClearViewPort(psurface);
            const char* psprite = LoadSprite("Bin/test_sprite.txt");
            if (psprite) {
                PlaceSpriteOnViewport(psurface, psprite, 100, 100);
                free((void*)psprite);
            }
            DisplayViewport(pwindow);
        }
    }

    // clean up resources before exiting.
    SDL_DestroyWindow(pwindow);
    SDL_Quit();
}