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
    PlayerSetSprite(&player, 0); // initial sprite

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
                        PlayerGoToDirection(&player, 0, -1);
                        PlayerSetSprite(&player, 2);
                        break;
                    case SDLK_DOWN:
                        PlayerGoToDirection(&player, 0, 1);
                        PlayerSetSprite(&player, 3);
                        break;
                    case SDLK_LEFT:
                        PlayerGoToDirection(&player, -1, 0);
                        PlayerSetSprite(&player, 1);
                        break;
                    case SDLK_RIGHT:
                        PlayerGoToDirection(&player, 1, 0);
                        PlayerSetSprite(&player, 0);
                        break;
                }
            }
        }

        // Display
        ClearViewPort(psurface);

        PlayerMove(&player);
        PlayerDisplay(&player, psurface);

        DisplayViewport(pwindow);
        SDL_Delay(3); // otherwise CPU goes brrr
    }

    // clean up resources before exiting.
    SDL_DestroyWindow(pwindow);
    SDL_Quit();
}