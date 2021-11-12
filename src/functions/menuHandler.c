#include "../headers/menuHandler.h"
#include "../headers/utils.h"
#include "../headers/menuData.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

static int menuOptionX = 1;
static int menuOptionY = 0;

// Macros para el manejador de teclas
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define UP_ARROW 72
#define DOWN_ARROW 80
#define ENTER 13
#define ESC 27




void goToMenu()
{
    switch (menuOptionX)
    {
    case 1:
        programsMenu();
        break;
    case 2:
        conceptsMenu();
    default:
        menuOptionX = 1;
        break;
    }
}

void programsMenu()
{
}

void conceptsMenu()
{
}

void exitProgram()
{
    clearScreen();
    centerTextWithColor(dataMenuExit, 12, 15, true);
    wchar_t c = (int) 246;
    setTerminalColor(12, 0);
    HANDLE handler = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cPos;
    int columns, rows;
    columns = getConsoleSize()[0];
    rows = getConsoleSize()[1];
    cPos.X = 30;
    cPos.Y = (rows / 2) + 1;
    SetConsoleCursorPosition(handler, cPos);
    for (float i = 0; i <= 90; i += 1.5)
    {
        Sleep(100);
        wprintf(L"%lc", c);
    }
    Sleep(1000);
    exit(0);
}

void centerCharWithColor(char character, int fgcolor, int bgcolor, bool centerH)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE handler = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cPos;
    int rows, columns;
    columns = getConsoleSize()[0];
    rows = getConsoleSize()[1];
    cPos.X = (columns - strlen(&character)) / 2;
    cPos.Y += 1;
    SetConsoleCursorPosition(handler, cPos);
    setTerminalColor(fgcolor, bgcolor);
    printf("%c", character);
}

void menu()
{
    initConsole(appTitle);
    centerTextWithColor(dataMenuControls, 11, 8, false);
    centerTextWithColor(dataMenuOptions, 12, 0, true);
    setTerminalFontProperties(24, 700);
    keyboardHandler();
}

void keyboardHandler()
{
    COORD cPos;
    while (1)
    {
        switch (getch())
        {
        case ENTER:
            printf("Position values: X:%d Y:%d", cPos.X, cPos.Y);
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cPos);
            puts("-");
            // goToMenu();
            break;
        case ESC:
            exitProgram();
            break;
        case UP_ARROW:
            cPos.Y++;
            break;
        case LEFT_ARROW:
            cPos.X--;
            break;
        case RIGHT_ARROW:
            cPos.X++;
            break;
        case DOWN_ARROW:
            cPos.Y--;
            break;
        }
    }
}