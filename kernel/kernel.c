#include "include/lib/print.h"
#include "include/keyboard/keyboard_waiting.h"
#include "include/keyboard/keyboard.h"
#include "include/lib/string.h"

extern void gdt_load();

void logo()
{
    print("NNN   NNN  EEEEEEEE   CCCCCCC   HH    HH  IIIIIIII      OOOOOOO   SSSSSSS\n");
    print("NNNN  NNN  EE        CC         HH    HH     II        OO     OO  SS\n");
    print("NN NN NNN  EEEEE     CC         HHHHHHHH     II        OO     OO   SSSSS\n");
    print("NN  NNNNN  EE        CC         HH    HH     II        OO     OO        SS\n");
    print("NN   NNNN  EEEEEEEE   CCCCCCC   HH    HH  IIIIIIII      OOOOOOO   SSSSSSS\n\n\n");
}

void basic_info()
{
    print("WELCOME TO NechiOS Terminal\n");
    print("Press any key to continue...\n");
}

void kernel_main()
{
    gdt_load();

    clear_screen();

    // Logo
    logo();

    // basic info
    basic_info();

    wait_any_key();

    clear_screen();

    print("NechiOS ");

    char command[256];

    while (1)
    {
        int pos = 0;
        print("> ");

        while (1)
        {
            char c = keyboard_get_char();

            if (c == '\n')
                break;

            if (c == '\b')
            {
                if (pos > 0)
                {
                    pos--;
                    backspace();
                }
                continue;
            }

            if (pos < 255 && c)
            {
                command[pos++] = c;
                print_char(c);
            }
        }

        if (pos == 0)
            continue;

        command[pos] = '\0';
        print_char('\n');

        if (strcmp(command, "help") == 0)
        {
            print("===========================\n");
            print("      HELP INFORMATION     \n");
            print("===========================\n");
            print("~ Commands:\n");
            print("1) clear - clear screen\n");
            print("2) help - help information\n");
        }
        else if (strcmp(command, "clear") == 0)
        {
            clear_screen();
        }
        else
        {
            print("Unknown command\n");
        }
    }

    while (1)
    {
        
    }
}
