#include <stdio.h>
#include <stdbool.h>

#include "display.h"
#include "player.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(void)
{
    SDL_Window* pwindow = CreateWindow("PacSDL", SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_Surface* psurface = SDL_GetWindowSurface(pwindow);

    Player player = { .x_pos = 100, .y_pos = 100 };

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
            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_UP:
                        GoToDirection(&player, 0, -1);
                        break;
                    case SDLK_DOWN:
                        GoToDirection(&player, 0, 1);
                        break;
                    case SDLK_LEFT:
                        GoToDirection(&player, -1, 0);
                        break;
                    case SDLK_RIGHT:
                        GoToDirection(&player, 1, 0);
                        break;
                }
            }
        }

        // Display
        ClearViewPort(psurface);

        MovePlayer(&player);

        const char* psprite = LoadSprite("Bin/test_sprite.txt", 0);
        if (psprite) {
            PlaceSpriteOnViewport(psurface, psprite, player.x_pos, player.y_pos);
            free((void*)psprite);
        }

        DisplayViewport(pwindow);
        SDL_Delay(3); // otherwise CPU goes brrr
    }

    // clean up resources before exiting.
    SDL_DestroyWindow(pwindow);
    SDL_Quit();
}