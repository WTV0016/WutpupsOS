#include "../include/kernel/stdio.h"

void kernel_main(void)
{
	TerminalInit();
	printS("Hello World!");
}