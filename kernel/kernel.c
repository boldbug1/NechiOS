#include "include/lib/print.h"

extern void gdt_load();
void terminal_init();
void shell_run();

void kernel_main()
{
    gdt_load();

    terminal_init();

    while (1)
    {
<<<<<<< HEAD
        shell_run();
=======
        update_cursor_blink();
>>>>>>> main
    }
}