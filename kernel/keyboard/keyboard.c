#include "include/keyboard/keyboard.h"
#include "include/keyboard/keyboard_waiting.h"

static char keymap[128] =
    {
        0,
        27, // ESC
        '1',
        '2',
        '3',
        '4',
        '5',
        '6',
        '7',
        '8',
        '9',
        '0',
        '-',
        '=',
        '\b', // Backspace
        '\t', // Tab
        'q',
        'w',
        'e',
        'r',
        't',
        'y',
        'u',
        'i',
        'o',
        'p',
        '[',
        ']',
        '\n', // Enter
        0,    // Ctrl
        'a',
        's',
        'd',
        'f',
        'g',
        'h',
        'j',
        'k',
        'l',
        ';',
        '\'',
        '`',
        0, // Shift
        '\\',
        'z',
        'x',
        'c',
        'v',
        'b',
        'n',
        'm',
        ',',
        '.',
        '/',
        0, // Shift
        '*',
        0,   // Alt
        ' ', // Space
};

char keyboard_get_char()
{
    unsigned char scancode;

    while (1)
    {
        scancode = keyboard_get_key();

        if (!(scancode & 0x80))
        {
            char c = keymap[scancode];

            if (c)
                return c;
        }

        
    }
}