#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>

#define COLOR_LENGTH 8
#define SPRITE_HEIGHT 12
#define SPRITE_WIDTH 12
#define SPRITE_SIZE SPRITE_HEIGHT * SPRITE_WIDTH * (COLOR_LENGTH+1)

const char* LoadSprite(const char* filepath, int whichSprite) {
    FILE *pfile = fopen(filepath, "r");
    if (!pfile) {
        perror("Failed to open file");
        return NULL;
    }

    fseek(pfile, (SPRITE_SIZE+2)*whichSprite, SEEK_SET); // Move to the right sprite

    char *pbuffer = malloc(SPRITE_SIZE);
    if (!pbuffer) {
        perror("Memory allocation failed");
        fclose(pfile);
        return NULL;
    }

    for(int i = 0; i < SPRITE_SIZE; i++) {
        fread(pbuffer + i, 1, 1, pfile);
    }

    printf("Loaded sprite %d\n", whichSprite);

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
