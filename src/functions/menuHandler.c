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
static int conceptMenuY = 0;
static int programMenuY = 0;

static bool isMainMenu = true;
static bool isRunning = true;
static bool isConceptMenu = false;
static bool isProgramMenu = false;

static COORD conceptsPos[25];
static COORD programsPos[19];

// Macros para el manejador de teclas
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define UP_ARROW 72
#define DOWN_ARROW 80
#define ENTER 13
#define ESC 27 
#define EasterEgg 9

void goToProgramMenu(int program){
    switch(program){
        case 0:
            clearScreen();
            centerTextWithColor(dataMenuControls[2], 12, 0, false);
            system("BinaryToDecimal.exe");
            if(getch() == ESC)
            {
                clearScreen();
                programsMenu();
            }
            break;
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        case 8:

            break;
        case 9:

            break;
        case 10:

            break;
        case 11:

            break;
        case 12:

            break;
        case 13:

            break;
        case 14:

            break;
        case 15:

            break;
        case 16:

            break;
        case 17:

            break;
        case 18:

            break;

    }
}

void goToConceptsMenu(int concept){
    switch(concept){
        case 0:
            clearScreen();
            centerTextWithColor(dataMenuControls[3], 12, 0, false);
            FILE *file;
            int character;
            file=fopen("1.1.txt","r");
            while((character=fgetc(file))!=EOF){
                putchar(character);
            }
            fclose(file);
            if(getch() == ESC)
            {
                clearScreen();
                conceptsMenu();
            }
            break;
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        case 8:

            break;
        case 9:

            break;
        case 10:

            break;
        case 11:

            break;
        case 12:

            break;
        case 13:

            break;
        case 14:

            break;
        case 15:

            break;
        case 16:

            break;
        case 17:

            break;
        case 18:

            break;

    }
}

void exitProgram()
{
    clearScreen();
    centerTextWithColor(dataMenuExit, 0, 0, true);
    int c = 219;
    HANDLE handler = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cPos;
    int columns, rows;
    columns = getConsoleSize()[0];
    rows = getConsoleSize()[1];
    cPos.X = 30;
    cPos.Y = (rows / 2) + 1;
    setlocale(LC_ALL, "C");
    SetConsoleCursorPosition(handler, cPos);
    setTerminalColor(14, 3);
    for (float i = 0; i <= 90; i += 1.5)
    {
        Sleep(10);
        wprintf(L"%lc", c);
    }
    Sleep(1000);
    isRunning = false;
}

void programsMenu()
{
    int columns = getConsoleSize()[0];
    clearScreen();
    centerTextWithColor(dataMenuControls[1], 12, 0, false);
    for (int counter = 0; counter < 20; counter++)
    {
        programsPos[counter].Y = 2;
        programsPos[counter].X = (columns - wcslen(dataMenuPractice[counter])) / 2;
        programsPos[counter].Y += counter + 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), programsPos[counter]);
        wprintf(L"%ls\n", dataMenuPractice[counter]);
    }
    programsPos[0].X = 30;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), programsPos[0]);
    printf("==>");
    setTerminalColor(0, 3);
}

void conceptsMenu()
{
    int columns = getConsoleSize()[0];
    clearScreen();
    centerTextWithColor(dataMenuControls[1], 12, 0, false);
    for (int counter = 0; counter < 26; counter++)
    {
       conceptsPos[counter].Y = 2;
       conceptsPos[counter].X = (columns - wcslen(dataMenuConcepts[counter])) / 2;
       conceptsPos[counter].Y += counter + 1;
        SetConsoleCursorPosition(GetStdHandle(((DWORD)-11)),conceptsPos[counter]);
        wprintf(L"%ls\n", dataMenuConcepts[counter]);
    }
    conceptsPos[0].X = 30;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), conceptsPos[0]);
    printf("==>");
    setTerminalColor(0, 3);
}

void goToSubMenu()
{
    switch (menuOptionX)
    {
    case 0:
        conceptsMenu();
        isConceptMenu = true;
        break;
    case 1:
        programsMenu();
        isProgramMenu = true;
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
    setTerminalColor(5, 3);
    keyboardHandler();
}

void printMarker(int subMenu)
{
    switch(subMenu)
    {
        case 0:
            for (int subMenuIterator_c = 0; subMenuIterator_c < 26; subMenuIterator_c++)
            {
                conceptsPos[subMenuIterator_c].X = 30;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), conceptsPos[subMenuIterator_c]);
                printf("   ");
            }
            conceptsPos[conceptMenuY].X = 30;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), conceptsPos[conceptMenuY]);
            printf("==>");
            break;
        case 1:
            for (int subMenuIterator_p = 0; subMenuIterator_p < 20; subMenuIterator_p++) 
            {
                programsPos[subMenuIterator_p].X = 30;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), programsPos[subMenuIterator_p]);
                printf("   ");
            }
            programsPos[programMenuY].X = 30;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), programsPos[programMenuY]);
            printf("==>");
            break;
    }
}

void keyboardHandler()
{
    while(isRunning)
    {
        switch(getch())
        {
            case EasterEgg:
                if (isMainMenu)
                {
                    MessageBox(NULL, "Jorge y Aaron", "Creado con amor por", MB_OK);
                }
                break;
            case ESC:
                if (isConceptMenu || isProgramMenu)
                {
                    clearScreen();
                    isMainMenu = true;
                    isConceptMenu = false;
                    isProgramMenu = false;
                    centerTextWithColor(dataMenuControls[0], 12, 0, false);
                    centerTextWithColor(dataMenuOptions[0], 12, 0, true);
                    setTerminalColor(5, 3);
                }
                break;
            case ENTER:
                if (isMainMenu) 
                {
                    goToSubMenu();
                    isMainMenu = false;
                }
                if (isProgramMenu && getch() == ENTER)
                {
                    goToProgramMenu(programMenuY);
                }
                if (isConceptMenu && getch() == ENTER)
                {
                    goToConceptsMenu(conceptMenuY);
                }
                
                break;
            case UP_ARROW:
                if (isConceptMenu)
                {
                    if (conceptMenuY == 0) 
                    {
                        conceptMenuY = 25;
                    }
                    else 
                    {
                        conceptMenuY--;
                    }
                    printMarker(0);
                }
                if (isProgramMenu)
                {
                    if (programMenuY == 0) 
                    {
                        programMenuY = 19;
                    }
                    else 
                    {
                        programMenuY--;
                    }
                    printMarker(1);
                }
                break;
            case DOWN_ARROW:
                if (isConceptMenu) 
                {
                    if (conceptMenuY == 25) 
                    {
                        conceptMenuY = 0;
                    }
                    else 
                    {
                        conceptMenuY++;
                    }
                    printMarker(0);
                }
                if (isProgramMenu) 
                {
                    if (programMenuY == 19) 
                    {
                        programMenuY = 0;
                    }
                    else
                    {
                        programMenuY++;
                    }
                    printMarker(1);
                }
                break;
            case LEFT_ARROW:
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
                    setTerminalColor(5, 3);
                }
                break;
            case RIGHT_ARROW:
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
                    setTerminalColor(5, 3);
                }
                break;
        }
    }
}