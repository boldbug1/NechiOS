#include "include/keyboard/keyboard_waiting.h"

static inline unsigned char inb(unsigned short port)
{
    unsigned char ret;
    __asm__ volatile("inb %1, %0"
                     : "=a"(ret)
                     : "Nd"(port));
    return ret;
}

unsigned char keyboard_get_key()
{
    unsigned char status;
    unsigned char keycode;

    while (1)
    {
        status = inb(0x64);

        if (status & 1)
        {
            keycode = inb(0x60);
            return keycode;
        }
    }
}

// по типу: Press any key to continue...
void wait_any_key()
{
    keyboard_get_key();
}

