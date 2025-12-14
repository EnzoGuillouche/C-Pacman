#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>

int main(void)
{
    SDL_Window* window = SDL_CreateWindow("PacSDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);

    bool running = true;
    while (running)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                running = false;
                break;
            }
        }
    }

    // clean up resources before exiting.
    SDL_DestroyWindow(window);
    SDL_Quit();
}