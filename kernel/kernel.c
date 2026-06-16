#include "include/lib/print.h"
#include "include/keyboard/keyboard_waiting.h"

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

    print("NechiOS:user@home<< ");

    while (1)
    {
        
    }
}