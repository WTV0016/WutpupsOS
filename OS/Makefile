all: clean grub

grub: kernel.bin
	cp kernel.bin isodir/boot/kernel.bin
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o myos.iso isodir

kernel.bin: boot.o kernel.o
	i386-elf-gcc -T linker.ld -o kernel.bin -ffreestanding -O2 -nostdlib boot.o kernel.o stdio.o stdmem.o -lgcc

boot.o:
	i386-elf-as arch/i386/boot.s -o boot.o

kernel.o:
	i386-elf-gcc -c kernel/kernel.c -o kernel.o -nostdlib -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	i386-elf-gcc -c arch/i386/stdio.c -o stdio.o -nostdlib -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	i386-elf-gcc -c arch/i386/stdmem.c -o stdmem.o -nostdlib -std=gnu99 -ffreestanding -O2 -Wall -Wextra

clean:
	rm -f *.o *.bin *.iso
	rm -f isodir/boot/kernel.bin isodir/boot/grub/grub.cfg