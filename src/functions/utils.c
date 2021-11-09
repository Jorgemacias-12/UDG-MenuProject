#include "../headers/utils.h"
#include <windows.h>
#include <cstring>
#include <conio.h>
#include <stdio.h>

#define BG_BLACK 0
#define FG_BLACK 0
#define BG_DARK_BLUE 1
#define FG_DARK_BLUE 1
#define BG_DARK_GREEN 2
#define FG_DARK_GREEN 2
#define BG_LIGHT_BLUE 3
#define FG_LIGHT_BLUE 3
#define BG_DARK_RED 4
#define FG_DARK_RED 4
#define BG_MAGENTA 5
#define FG_MAGENTA 5
#define BG_ORANGE 6
#define FG_ORANGE 6
#define BG_LIGHT_GRAY 7
#define FG_LIGHT_GRAY 7
#define BG_GRAY 8
#define FG_GRAY 8
#define BG_BLUEE 9
#define FG_BLUEE 9
#define BG_GREEN 10
#define FG_GREEN 10
#define BG_CYAN 11
#define FG_CYAN 11
#define BG_RED 12
#define FG_RED 12
#define BG_PINK 13
#define FG_PINK 13
#define BG_YELLOW 14
#define FG_YELLOW 14
#define BG_WHITE 15
#define FG_WHITE 15

int *getConsoleSize()
{
    static int consoleSize[2];
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(h, &csbi);
    consoleSize[0] = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    consoleSize[1] = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    return consoleSize;
}

void setTerminalColor(int fgcolor, int bgcolor)
{
    HANDLE handler = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD coord = {0, 0};
    DWORD dwNumWritten = 0;
    DWORD scrSize;
    GetConsoleScreenBufferInfo(handler, &csbi);
    scrSize = csbi.dwMaximumWindowSize.X * csbi.dwMaximumWindowSize.Y;
    WORD wColor = ((bgcolor & 0x0F) << 4) + (fgcolor & 0x0F);
    FillConsoleOutputAttribute(handler, wColor, scrSize, coord, &dwNumWritten);
    SetConsoleTextAttribute(handler, wColor);
}

void centerTextWithColor(char str[], int fgcolor, int bgcolor)
{
    int *consoleSize = getConsoleSize();
    int newWidth = strlen(str) + (consoleSize[0] - strlen(str)) / 2;
    WORD wColor = ((bgcolor & 0x0F) << 4) + (fgcolor & 0x0F);
    setTerminalColor(fgcolor, bgcolor);
    printf("%*s\n", newWidth, str);
}


void clearScreen()
{
    system("cls");
}
