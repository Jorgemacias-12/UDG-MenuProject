// void keyboardHandler()
// {
//     while (isRunning)
//     {
//         switch (getch())
//         {
//         case ENTER:
//             if (isMainMenu)
//             {
//                 goToMenu();
//                 isMainMenu = false;
//             }
//             if (!_kbhit()) 
//             {
//                 if (getch() == ENTER && isConceptMenu)
//                 {
//                     printf("Hello there!\n");
//                 }
//                 if (getch() == ENTER && isProgramMenu)
//                 {
//                     printf("Hello there!\n");
//                 }
//             }
//             break;
//         case ESC:
//             if (!isMainMenu)
//             {
//                 clearScreen();
//                 isMainMenu = true;
//                 isConceptMenu = false;
//                 isProgramMenu = false;
//                 centerTextWithColor(dataMenuControls[0], 12, 0, false);
//                 centerTextWithColor(dataMenuOptions[menuOptionX], 12, 0, true);
//             }
            
//             break;
//         case UP_ARROW:
//             if (isProgramMenu)
//             {
//                 if (programMenuY == 0)
//                 {
//                     programMenuY = 19;
//                 }
//                 else
//                 {
//                     programMenuY--;
//                 }
//                 printf("Value program: %d\n", programMenuY);
//             }
//             if (isConceptMenu)
//             {
//                 if (conceptMenuY == 0)
//                 {
//                     conceptMenuY = 24;
//                 }
//                 else
//                 {
//                     conceptMenuY--;
//                 }
//                 printf("Value program: %d\n", conceptMenuY);
//             }
//             break;
//         case DOWN_ARROW:
//             if (isProgramMenu)
//             {
//                 if (programMenuY == 19)
//                 {
//                     programMenuY = 0;
//                 }
//                 else
//                 {
//                     programMenuY++;
//                 }
//                 printf("Value program: %d\n", programMenuY);
//             }
//             if (isConceptMenu)
//             {
//                 if (conceptMenuY == 24)
//                 {
//                     conceptMenuY = 0;
//                 }
//                 else
//                 {
//                     conceptMenuY++;
//                 }
//                 printf("Value program: %d\n", conceptMenuY);
//             }
//             break;
//         case LEFT_ARROW:
//             // printf("Value: %d", menuOptionX); // Debes quitarlo
//             if (isMainMenu)
//             {
//                 if (menuOptionX == 0)
//                 {
//                     menuOptionX = 2;
//                 }
//                 else
//                 {
//                     menuOptionX--;
//                 }
//                 centerTextWithColor(dataMenuOptions[menuOptionX], 12, 0, true);
//             }
//             break;
//         case RIGHT_ARROW:
//             // printf("Value: %d", menuOptionX); // Debes quitarlo
//             if (isMainMenu)
//             {
//                 if (menuOptionX == 2)
//                 {
//                     menuOptionX = 0;
//                 }
//                 else
//                 {
//                     menuOptionX++;
//                 }
//                 centerTextWithColor(dataMenuOptions[menuOptionX], 12, 0, true);
//             }
//             break;
//         }
//     }
// }