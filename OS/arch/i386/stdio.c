#include"../../include/kernel/stdio.h"

uint8_t terminalColor;
uint16_t* VGA_BUFFER;
uint8_t terminalRow;
uint8_t terminalColumn;

static inline uint8_t GetVgaEntryColor(uint8_t foreground, uint8_t background)
{
    return foreground | background << 4;
}

static inline uint16_t GetVgaEntry(unsigned char uc, uint8_t vgaEntryColor)
{
    return (uint16_t) uc | (uint16_t) vgaEntryColor << 8;
}

int16_t GetStringLength(char* s)
{
    int16_t length = 0;

    while(s[length] != '\0')
    {
        length++;
    }

    return length;
}

void TerminalInit()
{
    terminalColor = GetVgaEntryColor(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
    terminalRow = terminalColumn = 0;
    VGA_BUFFER = 0xB8000;

    for(int x = 0; x < VGA_WIDTH; x++)
    {
        for(int y = 0; y < VGA_HEIGHT; y++)
        {
            VGA_BUFFER[(y * VGA_WIDTH) + x] = GetVgaEntry(' ', terminalColor);
        }
    }
}

void TerminalPutEntryAt(uint16_t vgaEntry, uint8_t x, uint8_t y)
{
    VGA_BUFFER[(y * VGA_WIDTH) + x] = vgaEntry;
}

void TerminalPutEntry(uint16_t vgaEntry)
{

}

void TerminalSetCursorPosition(uint8_t x, uint8_t y)
{
}

void TerminalSetColor(uint8_t color)
{

}

void putc(char c)
{

}

void printS(char* s)
{

}

void printI(int i, int inHex)
{

}
