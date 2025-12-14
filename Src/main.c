#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>

int main(void)
{
    SDL_Window* pwindow = SDL_CreateWindow("PacSDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);

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

            SDL_Surface* psurface = SDL_GetWindowSurface(pwindow);
            SDL_FillRect(psurface, NULL, 0xFF0000);
            SDL_UpdateWindowSurface(pwindow);
        }
    }

    // clean up resources before exiting.
    SDL_DestroyWindow(pwindow);
    SDL_Quit();
}