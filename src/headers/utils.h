#ifndef utils_h
#define utils_h
    extern int *getConsoleSize();
    extern void setTerminalColor(int fgcolor, int bgcolor);
    extern void centerTextWithColor(char str[], int fgcolor, int bgcolor);
    extern void clearScreen();
#endif