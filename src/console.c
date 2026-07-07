#ifndef _WIN32
#define _POSIX_C_SOURCE 200809L
#endif

#include "console.h"

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <conio.h>

void console_configure(void)
{
    system("mode con cols=120 lines=35");
}

void console_clear(void)
{
    system("cls");
}

void console_pause(void)
{
    system("pause");
}

void console_sleep_ms(unsigned int milliseconds)
{
    Sleep(milliseconds);
}

void console_set_color(const char *color_code)
{
    char command[32];
    snprintf(command, sizeof(command), "color %s", color_code);
    system(command);
}

void console_flash_background(const char *color_code, unsigned int milliseconds)
{
    console_set_color(color_code);
    console_sleep_ms(milliseconds);
    console_set_color("0F");
}

int console_kbhit(void)
{
    return _kbhit();
}

int console_getch(void)
{
    return _getch();
}

#else

#include <sys/select.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

static struct termios original_terminal;
static int terminal_is_configured = 0;

static void restore_terminal(void)
{
    if (terminal_is_configured) {
        tcsetattr(STDIN_FILENO, TCSANOW, &original_terminal);
    }
}

void console_configure(void)
{
    if (tcgetattr(STDIN_FILENO, &original_terminal) == 0) {
        struct termios raw_terminal = original_terminal;
        raw_terminal.c_lflag &= (tcflag_t) ~(ICANON | ECHO);
        raw_terminal.c_cc[VMIN] = 0;
        raw_terminal.c_cc[VTIME] = 0;
        if (tcsetattr(STDIN_FILENO, TCSANOW, &raw_terminal) == 0) {
            terminal_is_configured = 1;
            atexit(restore_terminal);
        }
    }

    printf("\033[8;35;120t");
    fflush(stdout);
}

void console_clear(void)
{
    printf("\033[2J\033[H");
    fflush(stdout);
}

void console_pause(void)
{
    printf("Press any key to continue . . .");
    fflush(stdout);
    (void)console_getch();
}

void console_sleep_ms(unsigned int milliseconds)
{
    struct timespec requested_time;
    requested_time.tv_sec = (time_t)(milliseconds / 1000U);
    requested_time.tv_nsec = (long)((milliseconds % 1000U) * 1000000UL);
    nanosleep(&requested_time, NULL);
}

static int hex_digit_to_int(char digit)
{
    if (digit >= '0' && digit <= '9') {
        return digit - '0';
    }
    if (digit >= 'A' && digit <= 'F') {
        return digit - 'A' + 10;
    }
    if (digit >= 'a' && digit <= 'f') {
        return digit - 'a' + 10;
    }
    return -1;
}

void console_set_color(const char *color_code)
{
    static const int foreground_codes[16] = {
        30, 34, 32, 36, 31, 35, 33, 37,
        90, 94, 92, 96, 91, 95, 93, 97
    };
    static const int background_codes[16] = {
        40, 44, 42, 46, 41, 45, 43, 47,
        100, 104, 102, 106, 101, 105, 103, 107
    };

    if (color_code == NULL || color_code[0] == '\0' || color_code[1] == '\0') {
        printf("\033[0m");
        fflush(stdout);
        return;
    }

    const int background = hex_digit_to_int(color_code[0]);
    const int foreground = hex_digit_to_int(color_code[1]);

    if (background < 0 || foreground < 0) {
        printf("\033[0m");
    } else {
        printf("\033[%d;%dm", background_codes[background], foreground_codes[foreground]);
    }
    fflush(stdout);
}

void console_flash_background(const char *color_code, unsigned int milliseconds)
{
    console_set_color(color_code);
    console_clear();
    console_sleep_ms(milliseconds);
    console_set_color("0F");
    console_clear();
}

int console_kbhit(void)
{
    fd_set read_fds;
    struct timeval timeout;

    FD_ZERO(&read_fds);
    FD_SET(STDIN_FILENO, &read_fds);

    timeout.tv_sec = 0;
    timeout.tv_usec = 0;

    return select(STDIN_FILENO + 1, &read_fds, NULL, NULL, &timeout) > 0;
}

int console_getch(void)
{
    unsigned char character = 0;

    while (read(STDIN_FILENO, &character, 1) != 1) {
        console_sleep_ms(10);
    }

    return (int)character;
}

#endif
