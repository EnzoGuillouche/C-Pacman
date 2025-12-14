#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>

#include "player.h"
#include "maze.h"
#include "collisions.h"

#define SCREEN_WIDTH MAZE_SPRITE_WIDTH*PIXEL_SIZE
#define SCREEN_HEIGHT MAZE_SPRITE_HEIGHT*PIXEL_SIZE

int main(void)
{
    SDL_Window* pwindow = CreateWindow("PacSDL", SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_Surface* psurface = SDL_GetWindowSurface(pwindow);

    
    Maze maze = { 
        .x_pos = 0, 
        .y_pos = 0 
    };
    MazeSetSprite(&maze);

    Player player = { 
        .x_pos = maze.x_pos+(MAZE_SPRITE_WIDTH/2)-(PLAYER_SPRITE_WIDTH/2), 
        .y_pos = maze.y_pos+MAZE_SPRITE_HEIGHT-(MAZE_SPRITE_HEIGHT/4)-(PLAYER_SPRITE_HEIGHT/2)+2,
    };
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

        MazeDisplay(&maze, psurface);
        
        if (CheckCollisions(&player, &maze)) {
            PlayerMove(&player);
        }
        PlayerDisplay(&player, psurface);

        DisplayViewport(pwindow);
        SDL_Delay(7); // otherwise CPU goes brrr
    }

    // clean up resources before exiting.
    SDL_DestroyWindow(pwindow);
    SDL_Quit();
}