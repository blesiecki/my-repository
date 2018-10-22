#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "game.h"
//Bartosz Lesiecki R00140299 CS2

void play_game()
{
    int counter = 0;
    printf("Xs and Os!\n");
    struct game* p_game_info = (struct game*)malloc(sizeof(struct game));

    printf("0x%X", (unsigned int)p_game_info);

    initialise_game (p_game_info, "John", "Annie");
    draw_banner();
    display_board(p_game_info->board);
    display_board_positions();
    while(p_game_info->status != DRAW)
    {
        print_status(p_game_info);
        process_move(p_game_info);
        display_board(p_game_info->board);
        check_win(p_game_info);
        counter++;
        if(counter == 9)
        {
            p_game_info->status = DRAW;
			p_game_info->finished = True;

        }

    }
    print_status(p_game_info);

}

void initialise_game(struct game* p_game_info, char* name1, char* name2)
{
    srand(time(0));
    int random = rand() % 2;
    p_game_info->status = random;
    for(int r=0; r < 3; r++)
    {
        for(int c=0; c < 3; c++)
        {
            p_game_info->board[r][c] = SPACE;
        }

    }
    p_game_info->finished = False;
    strncpy(p_game_info->playerNames[0], name1,MAX_NAME_LEN);
    strncpy(p_game_info->playerNames[1], name2,MAX_NAME_LEN);
}

void draw_banner()
{
    printf("\n----------------\n  GAME STATUS\n----------------");
}

void display_board(char board[3][3])
{
    int j=0;
    for(int r=0; r < 3; r++)
    {
        printf("\n ");
        int i=0;
        for(int c=0; c < 3; c++)
        {
            printf("%c", board[r][c]);
            if(i<2)
            {
                printf(" | ");
                i++;
            }
        }
        if(j<2)
        {
            printf("\n--- --- ---");
            j++;
        }
    }
}

void print_status(struct game* p_game_info)
{
    if(p_game_info->status == P1_TURN)
    {
        printf("\n%s's Turn" , p_game_info->playerNames[0]);
    }
    else if(p_game_info->status == P2_TURN)
    {
        printf("\n%s's Turn", p_game_info->playerNames[1]);
    }
    else if(p_game_info->status == P1_WON)
    {
        printf("\nWell done %s you have won", p_game_info->playerNames[0]);
    }
    else if(p_game_info->status == P2_WON)
    {
        printf("\nWell done %s you have won", p_game_info->playerNames[1]);
    }
    else if(p_game_info->status == DRAW)
    {
        printf("\nGame over, it's a draw");
    }
}

void display_board_positions()
{
    int j=0;
    int k=0;
    printf("\n ");
    for(int r=0; r < 3; r++)
    {
        printf("\n ");
        int i=0;
        for(int c=0; c < 3; c++)
        {
            printf("%d", k);
            k++;
            if(i<2)
            {
                printf(" | ");
                i++;
            }
        }
        if(j<2)
        {
            printf("\n--- --- ---");
            j++;
        }
    }

}

void get_row_col(int position, int* row, int* column)
{
    *column = position%3;
    *row = position/3;
}

void  process_move(struct game* p_game_info)
{
    int selection = 0;
    int row = 0;
    int col = 0;



    while (True)
    {
        printf("\nEnter a slot: ");
        scanf(" %d", &selection);
        if(selection < 0 || selection > 8)
        {
            printf("Invalid input, please try again ");
        }
        else
        {
            get_row_col(selection, &row, &col);
            if(p_game_info->board[row][col] != SPACE)
            {
                printf("Slot taken, try again ");
            }
            else
            {
                break;
            }
        }
    }
    //get_row_col(selection, &row, &col);


    if(p_game_info->status == P1_TURN)
    {
        p_game_info->board[row][col] = X_SYMBOL;
        p_game_info->status = P2_TURN;
    }
    else if(p_game_info->status == P2_TURN)
    {
        p_game_info->board[row][col] = O_SYMBOL;
        p_game_info->status = P1_TURN;
    }

}

void check_win(struct game* p_game_info)
{
    int winningPos[8][6] = {{0,0,0,1,0,2}, {1,0,1,1,1,2}, {2,0,2,1,2,2}, {0,0,1,0,2,0}, {0,1,1,1,2,1}, {0,2,1,2,2,2}, {0,0,1,1,2,2}, {0,2,1,1,2,0}};
    for(int y=0; y < 8; y++)
    {
        if(p_game_info->board[winningPos[y][0]][winningPos[y][1]] ==  p_game_info->board[winningPos[y][2]][winningPos[y][3]] && p_game_info->board[winningPos[y][2]][winningPos[y][3]] == p_game_info->board[winningPos[y][4]][winningPos[y][5]])
        {
            if(p_game_info->board[winningPos[y][0]][winningPos[y][1]] == X_SYMBOL)
            {
                p_game_info->status = P1_WON;
                p_game_info->finished = True;
                break;
            }
            else if(p_game_info->board[winningPos[y][0]][winningPos[y][1]] == O_SYMBOL)
            {
                p_game_info->status = P2_WON;
                p_game_info->finished = True;
                break;
            }
        }

    }
}
