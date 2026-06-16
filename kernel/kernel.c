#include "include/lib/print.h"

extern void gdt_load();

void kernel_main()
{
    gdt_load();

    print("Welcome to NechiOS...\n");
    print("Current app - Terminal");

    while (1)
    {
        
    }
}