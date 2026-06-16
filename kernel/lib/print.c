#include "../../include/lib/print.h"

int cursor_pos = 0;

static inline void outb(unsigned short port, unsigned char val)
{
    __asm__ volatile("outb %0, %1" : : "a"(val), "Nd"(port));
}

void set_cursor(int pos)
{
    outb(0x3D4, 0x0F);
    outb(0x3D5, (unsigned char)(pos & 0xFF));

    outb(0x3D4, 0x0E);
    outb(0x3D5, (unsigned char)((pos >> 8) & 0xFF));
}

void print(const char *str)
{
    unsigned short *vga = (unsigned short *)0xB8000;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '\n')
        {
            cursor_pos = (cursor_pos / 80 + 1) * 80;
            continue;
        }

        vga[cursor_pos] = (0x07 << 8) | str[i];
        cursor_pos++;

        if (cursor_pos >= 80 * 25)
            cursor_pos = 0; // пока без scroll
    }

    set_cursor(cursor_pos);
}

#define VGA ((unsigned short *)0xB8000)

void clear_screen()
{
    for (int i = 0; i < 80 * 25; i++)
        VGA[i] = (0x07 << 8) | ' ';

    cursor_pos = 0;
    set_cursor(cursor_pos);
}