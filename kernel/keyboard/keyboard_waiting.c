#include "include/keyboard/keyboard_waiting.h"

unsigned char keyboard_get_key()
{
    unsigned char scancode;

    while (1)
    {
        __asm__ volatile(
            "inb $0x60, %0"
            : "=a"(scancode));

        if (scancode != 0 && !(scancode & 0x80))
            return scancode;
    }
}

// по типу: Press any key to continue...
void wait_any_key()
{
    keyboard_get_key();
}

