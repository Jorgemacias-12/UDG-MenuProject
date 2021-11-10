#ifndef utils_h
#define utils_h

    #include <stdbool.h>

    extern int *getConsoleSize();
    extern void setTerminalColor(int fgcolor, int bgcolor);
    extern void centerTextWithColor(char str[], int fgcolor, int bgcolor, bool centerH);
    extern void setTerminalFontProperties(int fontSize, int fontStyle);
    extern void clearScreen();
#endif