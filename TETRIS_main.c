#define _USE_MATH_DEFINES

#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <math.h>

#include "TETRIS_functions.h" /*include functions*/


int main()
{

    system("mode con cols=120 lines=35"); /*set "cmd" size*/
    if (sign_TETRIS())
    {
        return 0; /*with the 'ESC' key*/
    }
    system("cls"); /*with the 'Enter' key : clear "sign_TETRIS" & Star Game!*/

    char game[80][30];     /*"Game" Array for Game Screen Display*/
    table_generator(game); /*Create game board*/
    int shape[5][2];       /*"Shape" array to display shapes*/
    int shape_shado[5][2]; /*"Shape_Shadow" array to clear the previous location of the shape when moving the shape*/

    int score = 0;       /*Variable "score" to save player points while playing and display it on the right side of the screen*/
    int next_shape = 4;  /*Variable "Next_shape" to store the next shape and display it on the right side of the screen*/
    int score_level = 0; /*Variable "Score_Level" To store a file of blocks that have been filled and must be removed*/
    int fallspeed = 200; /*Variable "FallSpeed" Amount of << Sleep() >>*/

    shape_generator(shape, shape_shado, next_shape);
    next_shape = random();                  /*Create a new shape to random*/
    game_updator(game, shape, shape_shado); /*Insert the shape coordinates in the Game array*/
    print_game(game, score, next_shape);    /*Print the Game array with << printf >>*/

    char ch; /*Variable "ch" for Cache the key pressed by the player*/

    while (1 /*Endless loop to run the game*/ )
    {

        while (!kbhit())
        { /* 1. The shapes will fall automatically.
             2. Score is controlled.
             3. The end of the game is controlled. */

            if ((s_shift(shape, shape_shado)) && (game_updator(game, shape, shape_shado)))                                                          /*<< 1 >>*/
            {
                print_game(game, score, next_shape); /*If the fall takes shape، the game continues.*/
            }
            else
            {
                fallspeed = 200; /*reset Variable "FallSpeed"*/
                shape_generator(shape, shape_shado, next_shape);
                next_shape = random(); /*Otherwise، the previous shape is fixed and the next shape will be created.*/
                while (score_sensor(game, score_level))                                                                                             /*<< 2 >>*/
                {                                                  /*Check the previous shape form has caused the score*/
                    score_level = score_sensor(game, score_level); /*In this case، the row number is stored in "Score_Level" variable.*/
                    print_game(game, score, next_shape);
                    if (score_level)
                    {
                        system("color A0"); /*color : Green - Black*/
                        Sleep(100);
                        system("color 0F"); /*color : Black - White (Default)*/
                        score += 20;                     /*Calculate new score*/
                        score_delete(game, score_level); /*Remove Filled Rows*/
                        print_game(game, score, next_shape);
                        score_level = 0; /*reset the "Score_Level" variable.*/
                    }
                }
            }
            if (gameover_sensor(game) /*The end of the game is controlled.*/)                                                                       /*<< 3 >>*/
            {
                if (sign_gameover()) /*Gameover*/
                {
                    return 0; /*with the 'ESC' key*/
                }
                else
                {
                    return main(); /*with the 'Enter' key*/
                }
            }
            Sleep(fallspeed);
        }

        if (kbhit)
        { /* 1. Move the shape to the left with the 'A' key.
             2. Move the shape to the right with the 'D' key.
             3. Increase the speed of fall with the 'S' key.
             4. Rotate shape with 'Space' key.
             5. Stop playing with the 'P' key.
             6. Cancel game with 'ESC' key.
             7. Undefined entries are controlled. */

            ch = getch();
            if (((int)ch == 97) || ((int)ch == 65))                                                                                                 /*<< 1 >>*/
            {
                if ((a_shift(shape, shape_shado)) && (game_updator(game, shape, shape_shado))) /*Limit "Left"*/
                {
                    print_game(game, score, next_shape); /*If the movement to the left was successful.*/
                }
            }
            else if (((int)ch == 100) || ((int)ch == 68))                                                                                           /*<< 2 >>*/
            {
                if ((d_shift(shape, shape_shado)) && (game_updator(game, shape, shape_shado))) /*Limit "Right"*/
                {
                    print_game(game, score, next_shape); /*If the movement to the right was successful.*/
                }
            }
            else if (((int)ch == 115) || ((int)ch == 83))                                                                                           /*<< 3 >>*/
            {
                if (fallspeed > 50) /*Limit "game speed"*/
                {
                    fallspeed -= 50; /*Increasing the speed of the game*/
                }
            }
            else if ((int)ch == 32)                                                                                                                 /*<< 4 >>*/
            {
                if ((spase_rotate(shape, shape_shado)) && (game_updator(game, shape, shape_shado))) /*Limit "Rotation"*/
                {
                    print_game(game, score, next_shape); /*If the rotation of the shape was successful.*/
                }
            }
            else if (((int)ch == 112) || ((int)ch == 80))                                                                                           /*<< 5 >>*/
            {
                system("color 0E"); /*color : Green - Black*/
                system("pause"); /*Stop playing*/
                system("color 0F"); /*color : Black - White (Default)*/
            }
            else if ((int)ch == 27)                                                                                                                 /*<< 6 >>*/
            {
                if (sign_gameover()) /*Cancel game*/
                {
                    return 0; /*with the 'ESC' key*/
                }
                else
                {
                    return main(); /*with the 'Enter' key*/
                }
            }
            else /*Undefined entry!*/                                                                                                               /*<< 7 >>*/
            {
                system("color 6E"); /*color : Orange - Black*/
                printf("You have entered : %c\nPlease pay attention to the guide\n", ch); /*Error Message*/
                system("color 0F"); /*color : Black - White (Default)*/
                system("pause"); /*Stop playing*/
            }
        }
    }
}