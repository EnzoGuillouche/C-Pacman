#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>

#define COLOR_LENGTH 8

const char* LoadSprite(const char* filepath) {
    FILE *pfile;
    char *pbuffer;
    int filelen;

    pfile = fopen(filepath, "rb");
    if (!pfile) {
        perror("Failed to open file");
        return NULL;
    }

    fseek(pfile, 0, SEEK_END);
    filelen = ftell(pfile);
    rewind(pfile);

    pbuffer = (char *)malloc(filelen + 1);
    if (!pbuffer) {
        perror("Memory allocation failed");
        fclose(pfile);
    }

    for(int i = 0; i < filelen; i++) {
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

    printf("Color: 0x%06X\n", color); // anyway, we have 0x00000 as default if we have error


    return color;
}
