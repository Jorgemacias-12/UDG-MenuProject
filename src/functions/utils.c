#include "headers/utils.h"
#include <windows.h>
#include <cstring>
#include <conio.h>
#include <stdlib.h>

int *getConsoleSize() 
{
    int  consoleSize[2];
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(h, &csbi);
    consoleSize[0] = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    consoleSize[1] = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    return consoleSize;
}

void setTerminalColor(int fgcolor, int bgcolor)
{
    WORD wColor = ((bgcolor & 0x0F) << 4) + (fgcolor & 0x0F);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

void centerText(char str[]) 
{
    int *consoleSize = getConsoleSize();
    int newWidth = strlen(str) + (consoleSize[0] - strlen(str)) / 2;
    printf("%*s\n", newWidth, str);
}