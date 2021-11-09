#include "../headers/menuHandler.h"
#include "../headers/utils.h"
#include "../headers/menuData.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void menuHandler(int menu)
{
}

void menu()
{
    centerTextWithColor(dataMenuControls, 15, 3);
    keyboardHandler();
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
                clearScreen();
                centerTextWithColor(dataMenuExit, 12, 15);
                Sleep(1000);
                exit(0);
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