#include "../headers/menuHandler.h"
#include "../headers/utils.h"
#include "../headers/menuData.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <locale.h>

static int menuOptionX = 0;
static int menuOptionY = 0;

static bool isMainMenu = true;

// Macros para el manejador de teclas
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define UP_ARROW 72
#define DOWN_ARROW 80
#define ENTER 13
#define ESC 27

void exitProgram()
{
    clearScreen();
    centerTextWithColor(dataMenuExit, 12, 15, true);
    int c = 219;
    setTerminalColor(12, 0);
    HANDLE handler = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cPos;
    int columns, rows;
    columns = getConsoleSize()[0];
    rows = getConsoleSize()[1];
    cPos.X = 30;
    cPos.Y = (rows / 2) + 1;
    setlocale(LC_ALL, "C");
    SetConsoleCursorPosition(handler, cPos);
    for (float i = 0; i <= 90; i += 1.5)
    {
        Sleep(100);
        wprintf(L"%lc", c);
    }
    Sleep(1000);
    exit(0);
}

void programsMenu()
{
    int columns = getConsoleSize()[0];
    clearScreen();
    setlocale(LC_ALL,"C");
    centerTextWithColor(dataMenuControls[1], 12, 0, false);
    setlocale(LC_ALL,"spanish");
    COORD cPos[19];
    for (int counter = 0; counter < 20; counter++) 
    {
        cPos[counter].Y = 2;
        cPos[counter].X = (columns - wcslen(dataMenuPractice[counter])) / 2;
        cPos[counter].Y += counter + 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cPos[counter]);
        wprintf(L"%ls\n", dataMenuPractice[counter]);
    }
}

void conceptsMenu()
{
    clearScreen();
    setlocale(LC_ALL, "C");
    centerTextWithColor(dataMenuControls[1], 12, 0, false);
    setlocale(LC_ALL, "spanish");
}

void goToMenu()
{
    switch (menuOptionX)
    {
    case 0:
        conceptsMenu();
        break;
    case 1:
        programsMenu();
        break;
    case 2:
        exitProgram();
        break;
    }
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
    cPos.Y = cPos.Y + 1;
    SetConsoleCursorPosition(handler, cPos);
    setTerminalColor(fgcolor, bgcolor);
    printf("%c", character);
}

void menu()
{
    initConsole(appTitle);
    centerTextWithColor(dataMenuControls[0], 11, 8, false);
    centerTextWithColor(dataMenuOptions[0], 12, 0, true);
    setTerminalFontProperties(24, 700);
    keyboardHandler();
}

void keyboardHandler()
{
    while (1)
    {
        switch (getch())
        {
        case ENTER:
            goToMenu();
            isMainMenu = false;
            break;
        case ESC:
            clearScreen(); 
            isMainMenu = true;
            centerTextWithColor(dataMenuControls[0], 12,0, false);
            centerTextWithColor(dataMenuOptions[menuOptionX], 12, 0, true);
            break;
        case UP_ARROW:
            break;
        case DOWN_ARROW:
            break;
        case LEFT_ARROW:
            // printf("Value: %d", menuOptionX); // Debes quitarlo
            if (isMainMenu)
            {
                if (menuOptionX == 0)
                {
                    menuOptionX = 2;
                }
                else
                {
                    menuOptionX--;
                }
                centerTextWithColor(dataMenuOptions[menuOptionX], 12, 0, true);
            }
            break;
        case RIGHT_ARROW:
            // printf("Value: %d", menuOptionX); // Debes quitarlo
            if (isMainMenu)
            {
                if (menuOptionX == 2)
                {
                    menuOptionX = 0;
                }
                else
                {
                    menuOptionX++;
                }
                centerTextWithColor(dataMenuOptions[menuOptionX], 12, 0, true);
            }
            break;
        }
    }
}