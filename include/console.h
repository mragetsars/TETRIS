#ifndef CONSOLE_H
#define CONSOLE_H

void console_configure(void);
void console_clear(void);
void console_pause(void);
void console_sleep_ms(unsigned int milliseconds);
void console_set_color(const char *color_code);
int console_kbhit(void);
int console_getch(void);

#endif
