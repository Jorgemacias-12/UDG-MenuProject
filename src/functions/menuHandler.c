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

void exitToProgramsMenu() 
{
    if(getch() == ESC)
    {
        clearScreen();
        programsMenu();
    }
}

void goToProgramMenu(int program)
{
    switch(program)
    {
        case 0:
            clearScreen();
            centerTextWithColor(dataMenuControls[2], 12, 0, false);
            system(dataProgramsRoute[0]);
            exitToProgramsMenu();
            break;
        case 1: 
            clearScreen();
            centerTextWithColor(dataMenuControls[2], 12, 0, false);
            system(dataProgramsRoute[1]);
            exitToProgramsMenu();
            break;
        case 2:
            clearScreen();
            centerTextWithColor(dataMenuControls[2], 12, 0, false);
            system(dataProgramsRoute[2]);
            exitToProgramsMenu();
            break;
        case 3:
            clearScreen();
            centerTextWithColor(dataMenuControls[2], 12, 0, false);
            system(dataProgramsRoute[3]);
            exitToProgramsMenu();
            break;
        case 4:
            clearScreen();
            centerTextWithColor(dataMenuControls[2], 12, 0, false);
            system(dataProgramsRoute[4]);
            exitToProgramsMenu();
            break;
        case 5:
            clearScreen();
            centerTextWithColor(dataMenuControls[2], 12, 0, false);
            system(dataProgramsRoute[5]);
            exitToProgramsMenu();
            break;
        case 6:
            clearScreen();
            centerTextWithColor(dataMenuControls[2], 12, 0, false);
            system(dataProgramsRoute[6]);
            exitToProgramsMenu();
            break;
        case 7:
            clearScreen();
            centerTextWithColor(dataMenuControls[2], 12, 0, false);
            system(dataProgramsRoute[7]);
            exitToProgramsMenu();
            break;
        case 8:
            clearScreen();
            centerTextWithColor(dataMenuControls[2], 12, 0, false);
            system(dataProgramsRoute[8]);
            exitToProgramsMenu();
            break;
        case 9:
            clearScreen();
            centerTextWithColor(dataMenuControls[2], 12, 0, false);
            system(dataProgramsRoute[9]);
            exitToProgramsMenu();
            break;
        case 10:
            clearScreen();
            centerTextWithColor(dataMenuControls[2], 12, 0, false);
            system(dataProgramsRoute[10]);
            exitToProgramsMenu();
            break;
        case 11:
            clearScreen();
            centerTextWithColor(dataMenuControls[2], 12, 0, false);
            system(dataProgramsRoute[11]);
            exitToProgramsMenu();
            break;
        case 12:
            clearScreen();
            centerTextWithColor(dataMenuControls[2], 12, 0, false);
            system(dataProgramsRoute[12]);
            exitToProgramsMenu();
            break;
        case 13:
            clearScreen();
            centerTextWithColor(dataMenuControls[2], 12, 0, false);
            system(dataProgramsRoute[13]);
            exitToProgramsMenu();
            break;
        case 14:
            clearScreen();
            centerTextWithColor(dataMenuControls[2], 12, 0, false);
            system(dataProgramsRoute[14]);
            exitToProgramsMenu();
            break;
        case 15:
            clearScreen();
            centerTextWithColor(dataMenuControls[2], 12, 0, false);
            system(dataProgramsRoute[15]);
            exitToProgramsMenu();
            break;
        case 16:
            clearScreen();
            centerTextWithColor(dataMenuControls[2], 12, 0, false);
            system(dataProgramsRoute[16]);
            exitToProgramsMenu();
            break;
        case 17:
            clearScreen();
            centerTextWithColor(dataMenuControls[2], 12, 0, false);
            system(dataProgramsRoute[17]);
            exitToProgramsMenu();
            break;
        case 18:
            clearScreen();
            centerTextWithColor(dataMenuControls[2], 12, 0, false);
            system(dataProgramsRoute[18]);
            exitToProgramsMenu();
            break;

    }
}

void exitToConceptsMenu()
{
    if(getch() == ESC)
    {
        clearScreen();
        conceptsMenu();
    }
}

void goToConceptsMenu(int concept){
    FILE *file;
    int character;
    switch(concept){
        case 0:
            clearScreen();
            centerTextWithColor(dataMenuControls[3], 12, 0, false);
            printf("\n");
            file=fopen(dataConceptsRoute[0],"r");
            while((character=fgetc(file))!=EOF){
                putchar(character);
            }
            fclose(file);
            exitToConceptsMenu();
            break;
        case 1:
            clearScreen();
            centerTextWithColor(dataMenuControls[3], 12, 0, false);
            file=fopen(dataConceptsRoute[1],"r");
            while((character=fgetc(file))!=EOF){
                putchar(character);
            }
            fclose(file);
            exitToConceptsMenu();
            break;
        case 2:
            clearScreen();
            centerTextWithColor(dataMenuControls[3], 12, 0, false);
            file=fopen(dataConceptsRoute[2],"r");
            while((character=fgetc(file))!=EOF){
                putchar(character);
            }
            fclose(file);
            exitToConceptsMenu();
            break;
        case 3:
            clearScreen();
            centerTextWithColor(dataMenuControls[3], 12, 0, false);
            file=fopen(dataConceptsRoute[3],"r");
            while((character=fgetc(file))!=EOF){
                putchar(character);
            }
            fclose(file);
            exitToConceptsMenu();
            break;
        case 4:
            clearScreen();
            centerTextWithColor(dataMenuControls[3], 12, 0, false);
            file=fopen(dataConceptsRoute[4],"r");
            while((character=fgetc(file))!=EOF){
                putchar(character);
            }
            fclose(file);
            exitToConceptsMenu();
            break;
        case 5:
            clearScreen();
            centerTextWithColor(dataMenuControls[3], 12, 0, false);
            file=fopen(dataConceptsRoute[5],"r");
            while((character=fgetc(file))!=EOF){
                putchar(character);
            }
            fclose(file);
            exitToConceptsMenu();
            break;
        case 6:
            clearScreen();
            centerTextWithColor(dataMenuControls[3], 12, 0, false);
            file=fopen(dataConceptsRoute[6],"r");
            while((character=fgetc(file))!=EOF){
                putchar(character);
            }
            fclose(file);
            exitToConceptsMenu();
            break;
        case 7:
            clearScreen();
            centerTextWithColor(dataMenuControls[3], 12, 0, false);
            file=fopen(dataConceptsRoute[7],"r");
            while((character=fgetc(file))!=EOF){
                putchar(character);
            }
            fclose(file);
            exitToConceptsMenu();
            break;
        case 8:
            clearScreen();
            centerTextWithColor(dataMenuControls[3], 12, 0, false);
            file=fopen(dataConceptsRoute[8],"r");
            while((character=fgetc(file))!=EOF){
                putchar(character);
            }
            fclose(file);
            exitToConceptsMenu();
            break;
        case 9:
            clearScreen();
            centerTextWithColor(dataMenuControls[3], 12, 0, false);
            file=fopen(dataConceptsRoute[9],"r");
            while((character=fgetc(file))!=EOF){
                putchar(character);
            }
            fclose(file);
            exitToConceptsMenu();
            break;
        case 10:
            clearScreen();
            centerTextWithColor(dataMenuControls[3], 12, 0, false);
            file=fopen(dataConceptsRoute[10],"r");
            while((character=fgetc(file))!=EOF){
                putchar(character);
            }
            fclose(file);
            exitToConceptsMenu();
            break;
        case 11:
            clearScreen();
            centerTextWithColor(dataMenuControls[3], 12, 0, false);
            file=fopen(dataConceptsRoute[11],"r");
            while((character=fgetc(file))!=EOF){
                putchar(character);
            }
            fclose(file);
            exitToConceptsMenu();
            break;
        case 12:
            clearScreen();
            centerTextWithColor(dataMenuControls[3], 12, 0, false);
            file=fopen(dataConceptsRoute[12],"r");
            while((character=fgetc(file))!=EOF){
                putchar(character);
            }
            fclose(file);
            exitToConceptsMenu();
            break;
        case 13:
            clearScreen();
            centerTextWithColor(dataMenuControls[3], 12, 0, false);
            file=fopen(dataConceptsRoute[13],"r");
            while((character=fgetc(file))!=EOF){
                putchar(character);
            }
            fclose(file);
            exitToConceptsMenu();
            break;
        case 14:
            clearScreen();
            centerTextWithColor(dataMenuControls[3], 12, 0, false);
            file=fopen(dataConceptsRoute[14],"r");
            while((character=fgetc(file))!=EOF){
                putchar(character);
            }
            fclose(file);
            exitToConceptsMenu();
            break;
        case 15:
            clearScreen();
            centerTextWithColor(dataMenuControls[3], 12, 0, false);
            file=fopen(dataConceptsRoute[15],"r");
            while((character=fgetc(file))!=EOF){
                putchar(character);
            }
            fclose(file);
            exitToConceptsMenu();
            break;
        case 16:
            clearScreen();
            centerTextWithColor(dataMenuControls[3], 12, 0, false);
            file=fopen(dataConceptsRoute[16],"r");
            while((character=fgetc(file))!=EOF){
                putchar(character);
            }
            fclose(file);
            exitToConceptsMenu();
            break;
        case 17:
            clearScreen();
            centerTextWithColor(dataMenuControls[3], 12, 0, false);
            file=fopen(dataConceptsRoute[17],"r");
            while((character=fgetc(file))!=EOF){
                putchar(character);
            }
            fclose(file);
            exitToConceptsMenu();
            break;
        case 18:
            clearScreen();
            centerTextWithColor(dataMenuControls[3], 12, 0, false);
            file=fopen(dataConceptsRoute[18],"r");
            while((character=fgetc(file))!=EOF){
                putchar(character);
            }
            fclose(file);
            exitToConceptsMenu();
            break;
        case 19:
            clearScreen();
            centerTextWithColor(dataMenuControls[3], 12, 0, false);
            file=fopen(dataConceptsRoute[19],"r");
            while((character=fgetc(file))!=EOF){
                putchar(character);
            }
            fclose(file);
            exitToConceptsMenu();
            break;
        case 20:
            clearScreen();
            centerTextWithColor(dataMenuControls[3], 12, 0, false);
            file=fopen(dataConceptsRoute[20],"r");
            while((character=fgetc(file))!=EOF){
                putchar(character);
            }
            fclose(file);
            exitToConceptsMenu();
            break;
        case 21:
            clearScreen();
            centerTextWithColor(dataMenuControls[3], 12, 0, false);
            file=fopen(dataConceptsRoute[21],"r");
            while((character=fgetc(file))!=EOF){
                putchar(character);
            }
            fclose(file);
            exitToConceptsMenu();
            break;
        case 22:
            clearScreen();
            centerTextWithColor(dataMenuControls[3], 12, 0, false);
            file=fopen(dataConceptsRoute[22],"r");
            while((character=fgetc(file))!=EOF){
                putchar(character);
            }
            fclose(file);
            exitToConceptsMenu();
            break;
        case 23:
            clearScreen();
            centerTextWithColor(dataMenuControls[3], 12, 0, false);
            file=fopen(dataConceptsRoute[23],"r");
            while((character=fgetc(file))!=EOF){
                putchar(character);
            }
            fclose(file);
            exitToConceptsMenu();
            break;
        case 24:
            clearScreen();
            centerTextWithColor(dataMenuControls[3], 12, 0, false);
            file=fopen(dataConceptsRoute[24],"r");
            while((character=fgetc(file))!=EOF){
                putchar(character);
            }
            fclose(file);
            exitToConceptsMenu();
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