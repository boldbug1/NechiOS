#pragma once

void print_char(char c);
void print(const char *str);

static inline void outb(unsigned short port, unsigned char val);
void set_cursor(int pos);

void clear_screen();

void backspace();