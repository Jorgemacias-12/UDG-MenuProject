#include "../headers/menuHandler.h"
#include "../headers/utils.h"
#include "../headers/menuData.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

void menuHandler(int menu)
{
}

void menu()
{
    setTerminalColor(11, 8);
    centerText(dataMenuControls);
}

void keyboardHandler()
{
    while (1)
    {
        system("cls");
        switch (getch())
        {
            case 13:
                break;
            case 27:
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