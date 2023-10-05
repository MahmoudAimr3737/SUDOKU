#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // Include this for the sleep function
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
int main()
{
    short arr[9][9] =
    {
        {'_', 0, 0, 0, 0, 0, 2*10, 0, 0}, // 1
        {0, 8*10, 0, 0, 0, 7*10, 0, 9*10, 0},  // 2
        {6*10, 0, 2*10, 0, 0, 0, 5*10, 0, 0},  // 3
        {0, 7*10, 0, 0, 6*10, 0, 0, 0, 0},  // 4
        {0, 0, 0, 9*10, 0, 1*10, 0, 0, 0},  // 5
        {0, 0, 0, 0, 2*10, 0, 0, 4*10, 0},  // 6
        {0, 0, 5*10, 0, 0, 0, 6*10, 0, 3*10},  // 7
        {0, 9*10, 0, 4*10, 0, 0, 0, 7*10, 0},  // 8
        {0, 0, 6*10, 0, 0, 0, 0, 0, 0}   // 9
    };

    short right_answer[9][9]=
    {
        {9, 5, 7, 6, 1, 3, 2, 8, 4},  // 1
        {4, 8, 3, 2, 5, 7, 1, 9, 6},  // 2
        {6, 1, 2, 8, 4, 9, 5, 3, 7},  // 3
        {1, 7, 8, 3, 6, 4, 9, 5, 2},  // 4
        {5, 2, 4, 9, 7, 1, 3, 6, 8},  // 5
        {3, 6, 9, 5, 2, 8, 7, 4, 1},  // 6
        {8, 4, 5, 7, 9, 2, 6, 1, 3},  // 7
        {2, 9, 1, 4, 3, 6, 8, 7, 5},  // 8
        {7, 3, 6, 1, 8, 5, 4, 2, 9}   // 9
    };
    int i = 0, j = 0;
    int x,size;
    char *p="why haven't you donated yet !!!!!\n";
    size=sizeof(p)/sizeof(p[0]);
    while(1)
    {
        instructions();
        printSudoku(arr);
        set_number(arr,&i,&j);
        x=compare_sudoku(arr,right_answer);
        if(x==0)
        {
            clearScreen();
        }
        if(x==1)
        {
            break;
        }


    }

    clearScreen();
    printf("                   !!!!!!!!!!!!!!!     CONGRATS     !!!!!!!!!!!!!!!\n");
    Sleep(2000);
    printf("                        %sgive us donation for next levels ^_^%s\n\n\n\n\n                          ",YELLOW,RESET);
    Sleep(5000);
    for(int k=0; p[k]; k++)
    {
        printf("%s%c%s",RED,p[k],RESET);
        Sleep(200); // Adjust the delay as needed
    }
    printf("\n\n");


    return 0;
}


