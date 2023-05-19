all: clean grub

grub: kernel.bin
	cp kernel.bin isodir/boot/kernel.bin
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o myos.iso isodir

kernel.bin: boot.o kernel.o
	i386-elf-gcc -T linker.ld -o kernel.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc

boot.o:
	i386-elf-as boot.s -o boot.o

kernel.o:
	i386-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

clean:
	rm -f *.o *.bin *.iso
	rm -f isodir/boot/kernel.bin isodir/boot/grub/grub.cfg