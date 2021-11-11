#include "../headers/menuHandler.h"
#include "../headers/utils.h"
#include "../headers/menuData.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

static int menuFlag;


void goToMenu()
{
    printf("Sheeesh");
}

void menuHandler(int menu, int menuOption)
{
}



void exitProgram()
{
    clearScreen();
    centerTextWithColor(dataMenuExit, 12, 15, true);
    char c=219;
    setTerminalColor(12, 0);
    HANDLE handler = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cPos;
    int columns, rows;
    columns = getConsoleSize()[0];
    rows = getConsoleSize()[1];
    cPos.X = 30;
    cPos.Y = (rows / 2) + 1;
    SetConsoleCursorPosition(handler, cPos);
    for (float i = 0; i <=90; i += 1.5)
    {
        Sleep(100);
        printf("%c", c);
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
    centerTextWithColor(dataMenuControls, 11, 8, false);
    centerTextWithColor(dataMenuDashboard, 11, 8, true);
    setTerminalFontProperties(24, 700);
    keyboardHandler();
}

void keyboardHandler()
{
    while (1)
    {
        switch (getch())
        {
        case 13:
            goToMenu();
            break;
        case 27:
            exitProgram();
            break;
        case 72:
            break;
        case 75:
            break;
        case 77:
            break;
        case 80:
            break;
        }
    }
}