TARGET := pmros.img
OBJS := entry.o main.o vgastr.o

ASM := nasm
CC  := gcc
LD  := ld

ASMFLAGS := -f elf32
CFLAGS   := -c -Os -std=c99 -m32 -Wall -Wextra -Werror -fno-pie -fno-stack-protector -fomit-frame-pointer -fno-builtin -fno-common -ffreestanding
LDFLAGS  := -s -static -T layout.ld -n -m elf_i386

.PHONY: all clean run docker docker-image

all: clean run

run: $(TARGET)
	qemu-system-x86_64 -curses -drive 'file=$<,format=raw,index=0,media=disk'
clean:
	rm -f $(TARGET) $(OBJS)

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

%.o: %.asm
	$(ASM) $(ASMFLAGS) -o $@ $<
%.o: %.c *.h
	$(CC) $(CFLAGS) -o $@ $<

docker: docker-image
	docker run --rm -it --name pmros-emu pmros-emu

docker-image: Dockerfile
	docker build -t pmros-emu .
