#include "../../include/kernel/stdmem.h"

void MemoryCopy(uint16_t *dest, uint16_t *src, uint16_t size)
{
    while (size--)
    {
        *dest++ = *src++;
    }
}

void MemorySet(uint16_t *dest, uint16_t val, uint16_t size)
{
    while (size--)
    {
        *dest++ = val;
    }
}