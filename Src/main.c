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

            r = 0xFF;
            g = 0x00;
            b = 0x00;
            UpdateViewport(psurface, 50, 50, r, g, b);
            DisplayViewport(pwindow);
        }
    }

    // clean up resources before exiting.
    SDL_DestroyWindow(pwindow);
    SDL_Quit();
}