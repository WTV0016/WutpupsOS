#include"../../include/kernel/stdio.h"
#include"../../include/kernel/stdmem.h"


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
    VGA_BUFFER = (uint16_t*)0xB8000;

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
    VGA_BUFFER[terminalRow * VGA_WIDTH + terminalColumn] = vgaEntry;
}

void TerminalSetCursorPosition(uint8_t x, uint8_t y)
{
    terminalColumn = x;
    terminalRow = y;
}

void TerminalSetColor(uint8_t color)
{
    terminalColor = color;
}

void TerminalClear()
{
    MemorySet(VGA_BUFFER, ' ', VGA_WIDTH * VGA_HEIGHT);
}

void ShiftContent()
{
    MemoryCopy(VGA_BUFFER, VGA_BUFFER + VGA_WIDTH, VGA_WIDTH * (VGA_HEIGHT - 1));
}

void putc(char c)
{
    if(c == '\n')
    {
        if(terminalRow >= VGA_HEIGHT - 1)
        {
            ShiftContent();
        }
        else
        {
            terminalRow++;
            terminalColumn = 0;
        }
    }
    else if(c == '\r')
    {
        terminalColumn = 0;
    }
    else
    {
        TerminalPutEntry(GetVgaEntry(c, terminalColor));
        terminalColumn++;
    }
}

void printS(char* s)
{
    uint16_t length = GetStringLength(s);

    for(uint16_t i = 0; i < length; i++)
    {
        putc(s[i]);
    }
}

void printI(int val, int inHex)
{
    char buffer[10]; // Buffer to hold the decimal digits
    int index = 0;
    int isNegative = 0;
    
    if(inHex)
    {
        // Convert the integer to hexadecimal format
        while (val >= 0) {
            int remainder = val % 16;
            
            if (remainder < 10)
                buffer[index++] = remainder + '0'; // Convert to ASCII digit
            else
                buffer[index++] = remainder - 10 + 'A'; // Convert to ASCII character A-F
            
            val /= 16;
        }
        
        // Print the hexadecimal digits in reverse order
        for (int i = index - 1; i >= 0; i--)
        {
                putc(buffer[i]);
        }
    }
    else
    {
        // Handle negative numbers
        if (val < 0) {
            isNegative = 1;
            val = -val;
        }
        
        // Convert the integer to decimal format
        while(val >= 0) {
            buffer[index++] = val % 10 + '0'; // Convert to ASCII digit
            val /= 10;
        }
        
        // Print the decimal digits in reverse order
        if (isNegative)
        {
            putc('-');
        }
        
        for (int i = index - 1; i >= 0; i--)
        {
            putc(buffer[i]);
        }    
    }
    
}
