#include "../headers/utils.h"
#include <windows.h>
#include <wchar.h>
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

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


void initConsole(LPCSTR appTitle)
{
    setlocale(LC_ALL, "spanish");
    SetConsoleTitle(appTitle);
    HWND console = GetConsoleWindow();
    SetWindowLong(console, GWL_STYLE, GetWindowLong(console, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}

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

void printAndGoToXY(wchar_t str[], int cPosX, int cPosY)
{
    int columns = getConsoleSize()[0];
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    COORD cPos = {csbi.dwCursorPosition.X, csbi.dwCursorPosition.Y};
    if (cPosX == 0)
    {
        cPos.X = (columns - 12) / 2;
    }
    else
    {
        cPos.X = cPosX;
    }
    if (cPosY == 0)
    {
        cPos.Y;
    }
    else 
    {
        cPos.Y = cPosY;
    }
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cPos);
    wprintf(L"%ls", str);
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

void centerTextWithColor(wchar_t str[], int fgcolor, int bgcolor, bool centerH)
{
    HANDLE handler = GetStdHandle(STD_OUTPUT_HANDLE);
    int rows, columns;
    columns = getConsoleSize()[0];
    rows = getConsoleSize()[1];
    COORD cPos;
    cPos.X = (columns - wcslen(str)) / 2;
    if (centerH)
    {
        cPos.Y = (rows - 1) / 2;
    }
    else
    {
        cPos.Y = cPos.Y + 1;
    }
    SetConsoleCursorPosition(handler, cPos);
    setTerminalColor(fgcolor, bgcolor);
    wprintf(L"%ls\n", str);
}

/* Font Weights */
#define FW_DONTCARE 0
#define FW_THIN 100
#define FW_EXTRALIGHT 200
#define FW_LIGHT 300
#define FW_NORMAL 400
#define FW_MEDIUM 500
#define FW_SEMIBOLD 600
#define FW_BOLD 700
#define FW_EXTRABOLD 800
#define FW_HEAVY 900

void setTerminalFontProperties(int fontSize, int fontStyle)
{
    HANDLE handler = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = fontSize;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = fontStyle;
    wcscpy(cfi.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(handler, false, &cfi);
}

void clearScreen()
{
    system("cls");
}