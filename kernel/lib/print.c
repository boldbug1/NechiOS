#include "include/lib/print.h"

int cursor_pos = 0;

void print_char(char c)
{
    unsigned short *vga = (unsigned short *)0xB8000;

    if (c == '\n')
    {
        cursor_pos = (cursor_pos / 80 + 1) * 80;
        return;
    }

    vga[cursor_pos] = (0x07 << 8) | c;
    cursor_pos++;
}

void print(const char *str)
{
    while (*str)
    {
        print_char(*str);
        str++;
    }
}

#define VGA ((unsigned short *)0xB8000)

void clear_screen()
{
    for (int i = 0; i < 80 * 25; i++)
        VGA[i] = (0x07 << 8) | ' ';

    cursor_pos = 0;
}

void backspace()
{
    if (cursor_pos > 0)
    {
        cursor_pos--;
        ((unsigned short *)0xB8000)[cursor_pos] = (0x07 << 8) | ' ';
    }
}