//#include"../include/kernel/stdio.h"

void kernel_main(void)
{
	//printS("Hello World!");
	asm volatile("cli");
	asm volatile("hlt");
}