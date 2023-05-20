#include "stdtypes.h"

#ifndef STDIO_H
#define STDIO_H

#define VGA_WIDTH 80
#define VGA_HEIGHT 25

#define VGA_COLOR_BLACK 0
#define VGA_COLOR_BLUE 1
#define VGA_COLOR_GREEN 2
#define VGA_COLOR_CYAN 3
#define VGA_COLOR_RED 4
#define VGA_COLOR_MAGENTA 5
#define VGA_COLOR_BROWN 6
#define VGA_COLOR_LIGHT_GREY 7
#define VGA_COLOR_DARK_GREY 8
#define VGA_COLOR_LIGHT_BLUE 9
#define VGA_COLOR_LIGHT_GREEN 10
#define VGA_COLOR_LIGHT_CYAN 11
#define VGA_COLOR_LIGHT_RED 12
#define VGA_COLOR_LIGHT_MAGENTA 13
#define VGA_COLOR_LIGHT_BROWN 14
#define VGA_COLOR_WHITE 15

static inline uint8_t GetVgaEntryColor(uint8_t foreground, uint8_t background);
static inline uint16_t GetVgaEntry(unsigned char uc, uint8_t vgaEntryColor);

int16_t GetStringLength(char* s);

void TerminalInit();
void TerminalSetEntryAt(uint16_t vgaEntry, uint8_t x, uint8_t y);
void TerminalSetEntry(uint16_t vgaEntry);
void TerminalSetCursorPosition(uint8_t x, uint8_t y);
void TerminalSetColor(uint8_t color);

void putc(char c);
void printS(char* s);
void printI(int i, int inHex);

#endif