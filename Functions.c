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
void clearScreen()
{
    printf("\033[2J");  // Clear the screen
    printf("\033[H");   // Move the cursor to the top-left corner
}
void printSudoku(short arr[][9])
{
    int i, j;
    for (i = 0; i < 9; i++)
    {
        if (i % 3 == 0)
        {
            printf("-------------------------------\n");
        }
        for (j = 0; j < 9; j++)
        {
            if (j % 3 == 0)
            {
                printf("|");
            }
            if (arr[i][j] == '_')
            {
                printf(" %s_%s ",BLUE,RESET);
            }
            else
            {
                if (arr[i][j] == 0)
                {
                    printf("%s * %s", GREEN, RESET);
                }
                else if(arr[i][j]>=10&&arr[i][j]<100)
                {
                    printf(" %s%d%s ", MAGENTA,arr[i][j]/10,RESET);
                }
                else if(arr[i][j]>=100)
                {
                    printf(" %s%d%s ", BLUE,arr[i][j]/100,RESET);
                }
                else
                {
                    printf(" %d ", arr[i][j]);
                }
            }
        }
        printf("|\n");
    }
    printf("-------------------------------\n");
}
void set_number(short arr[][9],short*i,short*j)
{
    short num, new_num;
    if(arr[*i][*j]>=100)
        arr[*i][*j]=arr[*i][*j]/100;
    fflush(std);
    scanf(" %c",&num); // Note the space before %c to consume any whitespace or newline characters.

    if (num == 'd'||num == 'D')
    {
        if(*i>=0&&*i<=8&&*j>=0&&*j<=81)
        {
            if(arr[*i][*j+1]<10||arr[*i][*j+1]==0)
            {
                if(arr[*i][*j] == '_')
                    arr[*i][*j] = 0;
                //if(*j<80) bug
                (*j)++;
                if(arr[*i][*j]>0&&arr[*i][*j]<=9)
                {
                    arr[*i][*j] = arr[*i][*j]*100;// mark for notify the user where he is standing
                }
                else
                    arr[*i][*j] = '_';
            }
            else
            {
                if(arr[*i][*j] == '_')
                    arr[*i][*j] = 0;
                (*j)=(*j)+2;
                if(arr[*i][*j]>0&&arr[*i][*j]<=9)
                {
                    arr[*i][*j] = arr[*i][*j]*100;// mark for notify the user where he is standing
                }
                else
                    arr[*i][*j] = '_';
            }
        }
    }
    else if (num == 'a'||num == 'A')
    {

        if(*i>=0&&*i<=8&&*j>=0&&*j<=81)//for stay in the array
        {
            if(arr[*i][*j-1]<10)//for save my orignal number
            {
                if(arr[*i][*j] == '_')//for saving the number that i stand on it
                    arr[*i][*j] = 0;// for restore th orignal shape *
                if(*j>0)//for stay in the array from moving left
                    (*j)=(*j)-1;
                if(arr[*i][*j]>0&&arr[*i][*j]<=9)//check if the next element is a number
                {
                    arr[*i][*j] = arr[*i][*j]*100;// mark for notify the user where he is standing
                }
                else
                    arr[*i][*j] = '_';
            }
            else//for skip th orignal number
            {
                if(arr[*i][*j] == '_')
                    arr[*i][*j] = 0;
                if(*j>0)//for stay in the array from moving left
                    (*j)=(*j)-2;
                if(arr[*i][*j]>0&&arr[*i][*j]<=9)
                {
                    arr[*i][*j] = arr[*i][*j]*100;// mark for notify the user where he is standing
                }
                else
                    arr[*i][*j] = '_';
            }
        }

    }
    else if (num == 's'||num == 'S')
    {
        if(*i>=0&&*i<=8&&*j>=0&&*j<=81)
        {
            if(arr[*i+1][*j]<10||arr[*i+1][*j]==0)
            {
                if(arr[*i][*j] == '_')
                    arr[*i][*j] = 0;
                if(*i<8)//for stay in the array from moving down
                    (*i)++;
                if(arr[*i][*j]>0&&arr[*i][*j]<=9)
                {
                    arr[*i][*j] = arr[*i][*j]*100;// mark for notify the user where he is standing
                }
                else
                    arr[*i][*j] = '_';
            }
            else
            {
                if(arr[*i][*j] == '_')
                    arr[*i][*j] = 0;
                if(*i<8)//for stay in the array from moving down
                    (*i)=(*i)+2;
                if(arr[*i][*j]>0&&arr[*i][*j]<=9)
                {
                    arr[*i][*j] = arr[*i][*j]*100;// mark for notify the user where he is standing
                }
                else
                    arr[*i][*j] = '_';
            }
        }
    }
    else if (num == 'w'||num == 'W')
    {
        if(*i>=0&&*i<=8&&*j>=0&&*j<=81)
        {
            if(arr[*i-1][*j]<10||arr[*i-1][*j]==0)
            {
                if(arr[*i][*j] == '_')
                    arr[*i][*j] = 0;
                if(*i>0)//for stay in the array from moving up
                    (*i)--;
                if(arr[*i][*j]>0&&arr[*i][*j]<=9)
                {
                    arr[*i][*j] = arr[*i][*j]*100;// mark for notify the user where he is standing
                }
                else
                    arr[*i][*j] = '_';
            }
            else
            {
                if(arr[*i][*j] == '_')
                    arr[*i][*j] = 0;
                if(*i>0)//for stay in the array from moving up
                    (*i)=(*i)-2;
                if(arr[*i][*j]>0&&arr[*i][*j]<=9)
                {
                    arr[*i][*j] = arr[*i][*j]*100;// mark for notify the user where he is standing
                }
                else
                    arr[*i][*j] = '_';

            }
        }


    }
    else if (num >= '1' && num <= '9')
    {
        new_num = num - '0';
        arr[*i][*j] = new_num*100;
    }

}
int compare_sudoku(short arr[][9],short result[][9])
{
    short copied[9][9];
    int i,j,end_game_flage=1;
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            copied[i][j]=arr[i][j];
            if(copied[i][j]>9&&copied[i][j]<100)
                copied[i][j]=copied[i][j]/10;
            if(copied[i][j]>100)
                copied[i][j]=copied[i][j]/100;
        }
    }
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            if(copied[i][j]!=result[i][j])
                end_game_flage=0;
        }
    }
    return end_game_flage;
}
void instructions(void)
{
    printf("%sControls.%s\n\n",RED,RESET);
    printf("%sright : d%s\n%sleft  : a%s\n%sup    : w%s\n%sdown  : s%s\n"
           ,CYAN,RESET,CYAN,RESET,CYAN,RESET,CYAN,RESET);
}
