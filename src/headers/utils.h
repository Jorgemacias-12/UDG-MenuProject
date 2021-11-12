#ifndef utils_h
#define utils_h

    #include <stdbool.h>
    #include <windows.h>

    extern int *getConsoleSize();
    extern void setTerminalColor(int fgcolor, int bgcolor);
    extern void centerTextWithColor(wchar_t str[], int fgcolor, int bgcolor, bool centerH);
    extern void centerCharWithColor(char character, int fgcolor, int bgcolor, bool centerH);
    extern void setTerminalFontProperties(int fontSize, int fontStyle);
    extern void clearScreen();
    extern void goToXY(int cPosX, int cPosY);
    extern void initConsole(LPCSTR appTitle);
#endif