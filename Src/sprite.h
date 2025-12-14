#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>

#define COLOR_LENGTH 8
#define PLAYER_SPRITE_HEIGHT 12
#define PLAYER_SPRITE_WIDTH 12
#define MAZE_SPRITE_HEIGHT 248
#define MAZE_SPRITE_WIDTH 224

const char* LoadSprite(const char* filepath, int HEIGHT, int WIDTH, int spriteIndex) {
    FILE *pfile = fopen(filepath, "r");
    if (!pfile) {
        perror("Failed to open file");
        return NULL;
    }

    fseek(pfile, ((HEIGHT*WIDTH*(COLOR_LENGTH+1))+2)*spriteIndex, SEEK_SET); // Move to the right sprite

    char *pbuffer = malloc((HEIGHT*WIDTH*(COLOR_LENGTH+1)));
    if (!pbuffer) {
        perror("Memory allocation failed");
        fclose(pfile);
        return NULL;
    }

    for(int i = 0; i < (HEIGHT*WIDTH*(COLOR_LENGTH+1)); i++) {
        fread(pbuffer + i, 1, 1, pfile);
    }

    fclose(pfile);

    return pbuffer;
}

Uint32 GetColorFromSprite(const char* pbuffer, int indexOfColor) {
    char colorStr[COLOR_LENGTH + 1];
    memcpy(colorStr, pbuffer + (COLOR_LENGTH*indexOfColor+indexOfColor), COLOR_LENGTH);
    colorStr[COLOR_LENGTH] = '\0';

    char *pend;
    Uint32 color = (Uint32)strtoul(colorStr, &pend, 0); // we convert to hexa number

    if (*pend != '\0') {
        fprintf(stderr, "Invalid color: %s\n", colorStr);
    }
    // anyway, we have 0x00000 as default if we have error

    return color;
}
