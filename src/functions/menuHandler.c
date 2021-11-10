#include "../headers/menuHandler.h"
#include "../headers/utils.h"
#include "../headers/menuData.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

static int menuFlag;

void menuHandler(int menu, int menuOption)
{
}

void menu()
{
    centerTextWithColor(dataMenuControls, 11, 8, false);
    centerTextWithColor(dataMenuDashboard, 11, 8, true);
    setTerminalFontProperties(26, 700);
    keyboardHandler();
}

void exitProgram()
{
    clearScreen();
    centerTextWithColor(dataMenuExit, 11, 8, true);
    char c=219;
    setTerminalColor(12, 0);
    for (float i = 0; i <= 80; i += 1.5)
    {
        Sleep(10);
        printf("%c", c);
        //progress[i] = i;
        //centerTextWithColor(progress, 11, 8, true);
    }
    exit(0);
}

void keyboardHandler()
{
    while (1)
    {
        switch (getch())
        {
        case 13:
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