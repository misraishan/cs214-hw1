#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>


void printBoard(int bx, int by, int px, int py, int gx, int gy, int mx, int my)
{
    for(int y = (by-1); y >= 0; y--)
    {
        for(int x = 0; x < bx; x++)
        {
            if(x == px && y == py)
                printf("P");
            else if(x == gx && y == gy)
                printf("G");
            else if(x == mx && y == my)
                printf("M");
            else
                printf(".");
            printf(" ");
        }
        printf("\n");
    }
}

int main(int argc, char** argv)
{
    //receive game information
    int boardx, boardy, plrx, plry, goalx, goaly, monx, mony;
    if(sscanf(argv[1], "%i", &boardx) != 1)
        fprintf(stderr, "error - not an integer, ending game...");
    if(sscanf(argv[2], "%i", &boardy) != 1)
        fprintf(stderr, "error - not an integer, ending game...");
    if(sscanf(argv[3], "%i", &plrx) != 1)
        fprintf(stderr, "error - not an integer, ending game...");
    if(sscanf(argv[4], "%i", &plry) != 1)
        fprintf(stderr, "error - not an integer, ending game...");
    if(sscanf(argv[5], "%i", &goalx) != 1)
        fprintf(stderr, "error - not an integer, ending game...");
    if(sscanf(argv[6], "%i", &goaly) != 1)
        fprintf(stderr, "error - not an integer, ending game...");
    if(sscanf(argv[7], "%i", &monx) != 1)
        fprintf(stderr, "error - not an integer, ending game...");
    if(sscanf(argv[8], "%i", &mony) != 1)
        fprintf(stderr, "error - not an integer, ending game...");

    // if (scanf("%d %d %d %d %d %d %d %d", boardx, boardy, plrx, plry, goalx, goaly, monx, mony) == EOF)
    // {
    //     printf("\nBAD INPUT: ending game...");
    //     exit(EXIT_SUCCESS);
    // }

    //is monster at goal already?
    if (goalx == monx && goaly == mony)
    {
        printf("\nMONSTER INITIALIZED AT GOAL, BAD INPUT: ending game...");
        exit(EXIT_SUCCESS);
    }
    
    //begin game, set moves
    char cmd;
    while(1==1)
    {
        bool move = true;
        printBoard(boardx, boardy, plrx, plry, goalx, goaly, monx, mony);
        if(scanf(" %c", &cmd)==EOF)
            break;
        if(plry+1 < boardy && (cmd == 'N' || cmd == 'n'))
            plry = plry+1;
        else if(plry-1 >= 0 && (cmd == 'S' || cmd == 's'))
            plry = plry-1;
        else if(plrx+1 < boardx && (cmd == 'E' || cmd == 'e'))
            plrx = plrx+1;
        else if(plrx-1 >= 0 && (cmd == 'W' || cmd == 'w'))
            plrx = plrx-1;
        else
        {
            printf("invalid move\n");
            move = false;
        }

        //decide how the monster moves if the player was able to move
        if(move)
        {
            //is player at goal
            if(plrx == goalx && plry == goaly)
            {
                printf("player wins!");
                exit(EXIT_SUCCESS);
            }

            //is player at monster?
            if(plrx == monx && plry == mony)
            {
                printf("monster wins!");
                exit(EXIT_SUCCESS);
            }

            //MONSTER MOVES
            //========================================================================================
            //Is it further away on the x field?
            if(abs(plrx-monx) > abs(plry-mony))
            {
                if((plrx-monx) > 0){ //move right
                    if(monx+1 != goalx || mony != goaly) //will it touch the goal? If yes forfeit turn
                    {
                        monx = monx+1;
                        printf("monster moves E\n");
                    }
                }
                else{ //move left
                    if(monx-1 != goalx || mony != goaly) //will it touch the goal? If yes forfeit turn
                    {    
                        monx = monx-1;
                        printf("monster moves W\n");
                    }
                }
            }
            //Is it further away on the y field?
            else if(abs(plrx-monx) < abs(plry-mony))
            {
                if((plry-mony) > 0){//move up
                    if(monx != goalx || mony+1 != goaly) //will it touch the goal? If yes forfeit turn
                    {
                        mony = mony+1;
                        printf("monster moves N\n");
                    }
                }
                else{ //move down
                    if(monx != goalx || mony-1 != goaly) //will it touch the goal? If yes forfeit turn
                    {
                        mony = mony-1;
                        printf("monster moves S\n");
                    }
                }
            }
            //Is the x and y distance the same?
            else
            {
                //randomly decide to move x or to move y
                srand(17);//WATCH VIDEO YOU TWAT AHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
                if(rand() % 50 >= 25)//move x
                {
                    if((plrx-monx) > 0){ //move right
                        if(monx+1 != goalx || mony != goaly) //will it touch the goal? If yes forfeit turn
                        {
                            monx = monx+1;
                            printf("monster moves E\n");
                        }
                    }
                    else{ //move left
                        if(monx-1 != goalx || mony != goaly) //will it touch the goal? If yes forfeit turn
                        {    
                            monx = monx-1;
                            printf("monster moves W\n");
                        }
                    }
                }
                else //move y
                {
                    if((plry-mony) > 0){ //move up
                        if(monx != goalx || mony+1 != goaly) //will it touch the goal? If yes forfeit turn
                        {
                            mony = mony+1;
                            printf("monster moves N\n");
                        }
                    }
                    else{ //move down
                        if(monx != goalx || mony-1 != goaly) //will it touch the goal? If yes forfeit turn
                        {
                            mony = mony-1;
                            printf("monster moves S\n");
                        }
                    }
                }
            }
            //============================================================================================

            //check again to see if player is at monster
            if(plrx == monx && plry == mony)
            {
                printf("monster wins!");
                exit(EXIT_SUCCESS);
            }
        }
    }
}