#define _USE_MATH_DEFINES

#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <math.h>

int sign_TETRIS(){
    system("color 03");
    printf("\n\n\n\n    _______________________________________________________________________________________________________________\n  ");
    printf(" |-> release in : 2023/12/19                                                                                     |\n  ");
    printf(" |                                             IN THE NAME OF GOD                                                |\n  ");
    printf(" |                                                WELCOME  TO                                                    |\n  ");
    printf(" |                                                                                                               |\n  ");
    printf(" |       << <<                #########   #######  #########  ######    #####   ######               >> >>       |\n  ");
    printf(" |     << <<                 #   #   #   #        #   #   #  #     #     #    #                        >> >>     |\n  ");
    printf(" |   << <<                      #       #####        #      ######      #     #####                      >> >>   |\n  ");
    printf(" |     << <<                   #       #            #      #  ##       #          #                    >> >>     |\n  ");
    printf(" |       << <<                #       #######      #      #    ##   #####  ######                    >> >>       |\n  ");
    printf(" |                                                                                                               |\n  ");
    printf(" |                                            BY : MERAJ RASTEGAR                                                |\n  ");
    printf(" |                                           Student ID  810102576                                               |\n  ");
    printf(" |_______________________________________________________________________________________________________________|\n  ");
    printf("                                                                                                                  \n  ");
    printf("                                        << Enter key [Enter] to play >>                                           \n  ");
    printf("                                                                                                                  \n  ");
    printf("                                         << Enter key [Esc] to exit >>                                            \n  ");
    char ch1;
	while (1) {
		if (kbhit) {
			ch1 = getch();
			if ((int)ch1 == 13){
                system("color 0F");
                return 0;
			}else if((int)ch1 == 27){
				return 1;
			}else{printf("You have entered : %c\n", ch1);}
		}
	}
}

void table_generator(char game[80][30]){

    for (int j = 0; j < 30; j++){
        for (int i = 0; i < 80; i++){
            if(i == 40 || i == 79){
                game[i][j]= 124;  
            }else if((j == 29)&&(i > 40)&&(i < 79)){
                game[i][j]= 84; 
            }else{
                game[i][j]= 32; 
            }
        }
    }
    char guide[16][19]={{' ','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',' '},
                        {'|','-','>',' ','g','u','i','d','e',':',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                        {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                        {'|',' ',' ',' ','L','E','F','T',' ',':',' ','<','A','>',' ',' ',' ',' ','|'},
                        {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                        {'|',' ',' ','R','I','G','H','T',' ',':',' ','<','D','>',' ',' ',' ',' ','|'},
                        {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                        {'|',' ',' ','R','O','T','A','T',' ',':',' ','s','p','a','c','e',' ',' ','|'},
                        {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                        {'|',' ',' ','S','P','E','E','D',' ',':',' ','<','S','>',' ',' ',' ',' ','|'},
                        {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                        {'|',' ',' ','P','A','U','S','E',' ',':',' ','<','P','>',' ',' ',' ',' ','|'},
                        {'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
                        {'|',' ',' ',' ','E','X','I','T',' ',':',' ','e','s','c',' ',' ',' ',' ','|'},
                        {'|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|'}};
    for (int j = 9; j < 24; j++){
        for (int i = 9; i < 28; i++){
            game[i][j]=guide[j-9][i-9];
        }
    }
}

int random(){
    srand(clock() + time(0) + M_PI);
    int randshape = rand() % 4;
    return randshape;
}

void shape_generator(int shape[5][2] , int shape_shado[5][2] , int next_shape){

    for(int j = 0; j < 2; j++){
        for(int i = 0; i < 5; i++){
            shape[i][j] = 0;
        }
    }
    for(int j = 0; j < 2; j++){
        for(int i = 0; i < 5; i++){
            shape_shado[i][j] = 0;
        }
    }
    
    if(next_shape == 4){shape[4][0] = random();}else{shape[4][0] = next_shape;}
    shape[4][1] = 1;
    if(shape[4][0] == 0){
            /* O_shape */
            int O_shape[4][2] = {{60,1},{62,1},{60,2},{62,2}};  /*[][]
        														  [][]*/

        for (int j = 0; j < 2; j++){
            for (int i = 0; i < 4; i++){
                shape[i][j] = O_shape[i][j];
            }
        }       
    }
    if(shape[4][0] == 1){
            /* I_shape */
            int I_shape[4][2] = {{60,1},{60,2},{60,3},{60,4}};  /*[]
				        										  []
		        												  []
        														  []*/
                                                                  
        for (int j = 0; j < 2; j++){
            for (int i = 0; i < 4; i++){
                shape[i][j] = I_shape[i][j];
            }
        }
    }
    if(shape[4][0] == 2){
           /* Z_shape */
           int Z_shape[4][2] = {{58,1},{60,1},{60,2},{62,2}};  /*[][]
    															   [][]*/
                                                                 
        for (int j = 0; j < 2; j++){
            for (int i = 0; i < 4; i++){
                shape[i][j] = Z_shape[i][j];
            }
        }
    }
    if(shape[4][0] == 3){
            /* T_shape */
            int T_shape[4][2] = {{60,1},{58,2},{60,2},{62,2}};  /*  []  
													        	  [][][]*/

        for (int j = 0; j < 2; j++){
            for (int i = 0; i < 4; i++){
                shape[i][j] = T_shape[i][j];
            }
        }
    }
    // if(shape[4][0] == 4){
    //        /* L_shape */
    //        int L_shape[4][2] = {{60,1},{60,2},{60,3},{62,3}};  /*[]
	// 										        		   	    []
	// 										        			    [][]*/
    //                                                           
    //     for (int j = 0; j < 2; j++){
    //         for (int i = 0; i < 4; i++){
    //             shape[i][j] = L_shape[i][j];
    //         }
    //     }
    // }
    for(int j = 0; j < 2; j++){
        for(int i = 0; i < 5; i++){
            shape_shado[i][j] = shape[i][j];
        }
    }
}

int a_shift(int shape[5][2] , int shape_shado[5][2]){
    int a_sensor = 0;
        for(int i = 0; i < 4; i++){
            if (shape[i][0] > 42){a_sensor++;}
        }
    if(a_sensor == 4){
        for(int j = 0; j < 2; j++){
            for(int i = 0; i < 4; i++){
                shape_shado[i][j] = shape[i][j];
                shape[i][0] --;
            }
        }
    }else{return 0;}
return 1;
}

int d_shift(int shape[5][2] , int shape_shado[5][2]){
    int d_sensor = 0;
        for(int i = 0; i < 4; i++){
            if (shape[i][0] < 77){d_sensor++;}
        }
    if(d_sensor == 4){
        for(int j = 0; j < 2; j++){
            for(int i = 0; i < 4; i++){
               shape_shado[i][j] = shape[i][j];
                shape[i][0] ++;
            }
        }
    }else{return 0;}
return 1;
}

int s_shift(int shape[5][2] , int shape_shado[5][2]){
    int s_sensor = 0;
        for(int i = 0; i < 4; i++){
            if (shape[i][1] < 28){s_sensor++;}
        }
    if(s_sensor == 4){    
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 2; j++){
                shape_shado[i][j] = shape[i][j];
            }
        shape[i][1] ++;
        }
    }else{return 0;}
return 1;
}

int spase_rotate(int shape[5][2] , int shape_shado[5][2]){
    
    for(int j = 0; j < 2; j++){
        for(int i = 0; i < 4; i++){
            shape_shado[i][j] = shape[i][j];
        }
    }
    
    if(shape[4][0] == 1){
        if(shape[4][1] == 1){
            
            if((shape[0][0]>41)&&(shape[0][1]<28)&&(shape[2][0]<78)&&(shape[2][1]>2)&&(shape[3][0]<76)&&(shape[3][1]>3)){
            shape[0][0] --;shape[0][0] --;
            shape[0][1] ++;
            shape[2][0] ++;shape[2][0] ++;
            shape[2][1] --;
            shape[3][0] += 2;shape[3][0] += 2;
            shape[3][1] -= 2;
            
            shape[4][1] = 2;
            return 1;
            }else{return 0;}
        }
    
        if(shape[4][1] == 2){
            
            if((shape[0][0]<78)&&(shape[0][1]>2)&&(shape[2][0]>41)&&(shape[2][1]<28)&&(shape[3][0]>42)&&(shape[3][1]<27)){
            shape[0][0] ++;shape[0][0] ++;
            shape[0][1] --;
            shape[2][0] --;shape[2][0] --;
            shape[2][1] ++;
            shape[3][0] -= 2;shape[3][0] -= 2;
            shape[3][1] += 2;
            
            shape[4][1] = 1;
            return 1;
            }else{return 0;}
        }
    }
    if(shape[4][0] == 2){
            if(shape[4][1] == 1){
            
            if((shape[0][0]<78)&&(shape[1][1]<28)&&(shape[2][0]>41)&&(shape[3][0]>42)&&(shape[3][1]<28)){
            shape[0][0] ++;shape[0][0] ++;
            shape[1][1] ++;
            shape[2][0] --;shape[2][0] --;
            shape[3][0] -= 2;shape[3][0] -= 2;
            shape[3][1] ++;
            
            shape[4][1] = 2;
            return 1;
            }else{return 0;}
        }
    
        if(shape[4][1] == 2){
            
            if((shape[0][0]>41)&&(shape[1][1]>2)&&(shape[2][0]<78)&&(shape[3][0]<77)&&(shape[3][1]>2)){
            shape[0][0] --;shape[0][0] --;
            shape[1][1] --;
            shape[2][0] ++;shape[2][0] ++;
            shape[3][0] += 2;shape[3][0] += 2;
            shape[3][1] --;
            
            shape[4][1] = 1;
            return 1;
            }else{return 0;}
        }
    }
    if(shape[4][0] == 3){
        if(shape[4][1] == 1){
            
            if((shape[0][0]<78)&&(shape[0][1]<28)&&(shape[1][0]<78)&&(shape[1][1]>2)&&(shape[3][0]>41)&&(shape[3][1]<28)){
            shape[0][0] ++;shape[0][0] ++;
            shape[0][1] ++;
            shape[1][0] ++;shape[1][0] ++;
            shape[1][1] --;
            shape[3][0] --;shape[3][0] --;
            shape[3][1] ++;
            
            shape[4][1] = 2;
            return 1;
            }else{return 0;}
        }
    
        if(shape[4][1] == 2){
            
            if((shape[0][0]>41)&&(shape[0][1]<28)&&(shape[1][0]<78)&&(shape[1][1]<28)&&(shape[3][0]>41)&&(shape[3][1]>2)){
            shape[0][0] --;shape[0][0] --;
            shape[0][1] ++;
            shape[1][0] ++;shape[1][0] ++;
            shape[1][1] ++;
            shape[3][0] --;shape[3][0] --;
            shape[3][1] --;
            
            shape[4][1] = 3;
            return 1;
            }else{return 0;}
        }
        if(shape[4][1] == 3){
            
            if((shape[0][0]>41)&&(shape[0][1]>2)&&(shape[1][0]>41)&&(shape[1][1]<28)&&(shape[3][0]<78)&&(shape[3][1]>2)){
            shape[0][0] --;shape[0][0] --;
            shape[0][1] --;
            shape[1][0] --;shape[1][0] --;
            shape[1][1] ++;
            shape[3][0] ++;shape[3][0] ++;
            shape[3][1] --;
            
            shape[4][1] = 4;
            return 1;
            }else{return 0;}
        }
        if(shape[4][1] == 4){
            
            if((shape[0][0]<78)&&(shape[0][1]>2)&&(shape[1][0]>41)&&(shape[1][1]>2)&&(shape[3][0]<78)&&(shape[3][1]<28)){
            shape[0][0] ++;shape[0][0] ++;
            shape[0][1] --;
            shape[1][0] --;shape[1][0] --;
            shape[1][1] --;
            shape[3][0] ++;shape[3][0] ++;
            shape[3][1] ++;
            
            shape[4][1] = 1;
            return 1;
            }else{return 0;}
        }
    }
}

int game_updator(char game[80][30] , int shape[5][2] , int shape_shado[5][2]){
    
    for (int j = 0; j < 29; j++){
        for (int i = 41; i < 79; i++){
            if((i == shape_shado[0][0])&&(j == shape_shado[0][1])){
                game[i][j]= 32;
                game[i-1][j]= 32;
            }
            if((i == shape_shado[1][0])&&(j == shape_shado[1][1])){
                game[i][j]= 32;
                game[i-1][j]= 32;
            }
            if((i == shape_shado[2][0])&&(j == shape_shado[2][1])){
                game[i][j]= 32;
                game[i-1][j]= 32;
            }
            if((i == shape_shado[3][0])&&(j == shape_shado[3][1])){
                game[i][j]= 32;
                game[i-1][j]= 32;
            } 
        }
    }
    int i_sensor = 0;
    for (int j = 0; j < 29; j++){
        for (int i = 41; i < 79; i++){
            if((i == shape[0][0])&&(j == shape[0][1])){
                if(game[i][j] == 32){i_sensor ++;}
                if(game[i-1][j] == 32){i_sensor ++;}
            }
            if((i == shape[1][0])&&(j == shape[1][1])){
                if(game[i][j] == 32){i_sensor ++;}
                if(game[i-1][j] == 32){i_sensor ++;}
            }
            if((i == shape[2][0])&&(j == shape[2][1])){
                if(game[i][j] == 32){i_sensor ++;}
                if(game[i-1][j] == 32){i_sensor ++;}
            }
            if((i == shape[3][0])&&(j == shape[3][1])){
                if(game[i][j] == 32){i_sensor ++;}
                if(game[i-1][j] == 32){i_sensor ++;}
            }
        } 
    }
    if(i_sensor != 8){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 2; j++){
                shape[i][j] = shape_shado[i][j];
            }
        }
        for (int j = 0; j < 29; j++){
            for (int i = 41; i < 79; i++){
                if((i == shape[0][0])&&(j == shape[0][1])){
                    game[i][j] = 93;
                    game[i-1][j] = 91;
                }
                if((i == shape[1][0])&&(j == shape[1][1])){
                    game[i][j] = 93;
                    game[i-1][j] = 91;
                }
                if((i == shape[2][0])&&(j == shape[2][1])){
                    game[i][j] = 93;
                    game[i-1][j] = 91;
                }
                if((i == shape[3][0])&&(j == shape[3][1])){
                    game[i][j] = 93;
                    game[i-1][j] = 91;
                }
            } 
        }
    return 0;
    }
    for (int j = 0; j < 29; j++){
        for (int i = 41; i < 79; i++){
            if((i == shape[0][0])&&(j == shape[0][1])){
                game[i][j] = 93;
                game[i-1][j] = 91;
            }
            if((i == shape[1][0])&&(j == shape[1][1])){
                game[i][j] = 93;
                game[i-1][j] = 91;
            }
            if((i == shape[2][0])&&(j == shape[2][1])){
                game[i][j] = 93;
                game[i-1][j] = 91;
            }
            if((i == shape[3][0])&&(j == shape[3][1])){
                game[i][j] = 93;
                game[i-1][j] = 91;
            }
        } 
    }
    if(i_sensor == 8){return 1;}
}

void print_game(char game[80][30] , int score , int next_shape){
system("cls");
    for(int j = 0; j < 30; j++){
        for(int i = 0; i < 80; i++){
            printf("%c",game[i][j]);
            if ((j == 9)&&(i == 79)){
                    printf("             ________________");
            }
            if ((j == 10)&&(i == 79)){
                    printf("            |-> next shape:  |");
            }
            if ((j == 11)&&(i == 79)){
                    printf("            |                |");
            }
            if(next_shape == 0){
                if ((j == 12)&&(i == 79)){
                    printf("            |                |");
                }
                if ((j == 13)&&(i == 79)){
                    printf("            |      [][]      |");
                }
                if ((j == 14)&&(i == 79)){
                    printf("            |      [][]      |");
                }
                if ((j == 15)&&(i == 79)){
                    printf("            |                |");
                }
            }
            if(next_shape == 1){
                if ((j == 12)&&(i == 79)){
                    printf("            |       []       |");
                }
                if ((j == 13)&&(i == 79)){
                    printf("            |       []       |");
                }
                if ((j == 14)&&(i == 79)){
                    printf("            |       []       |");
                }
                if ((j == 15)&&(i == 79)){
                    printf("            |       []       |");
                }
            }
            if(next_shape == 2){
                if ((j == 12)&&(i == 79)){
                    printf("            |                |");
                }
                if ((j == 13)&&(i == 79)){
                    printf("            |     [][]       |");
                }
                if ((j == 14)&&(i == 79)){
                    printf("            |       [][]     |");
                }
                if ((j == 15)&&(i == 79)){
                    printf("            |                |");
                }
            }
            if(next_shape == 3){
                if ((j == 12)&&(i == 79)){
                    printf("            |                |");
                }
                if ((j == 13)&&(i == 79)){
                    printf("            |       []       |");
                }
                if ((j == 14)&&(i == 79)){
                    printf("            |     [][][]     |");
                }
                if ((j == 15)&&(i == 79)){
                    printf("            |                |");
                }
                
            }
            if ((j == 16)&&(i == 79)){
                    printf("            |________________|");
            }
            if ((j == 19)&&(i == 79)){
                    printf("             ________________");
            }
            if ((j == 20)&&(i == 79)){
                    printf("            |-> score:       |");
            }
            if ((j == 21)&&(i == 79)){
                    printf("            |                |");
                }
            if ((j == 22)&&(i == 78)){
                if(score / 10 == 0){
                    printf("|            |     << %d >>    ",score);
                }
                else if(score / 100 == 0){
                    printf("|            |    << %d >>    ",score);
                }
                else if(score / 1000 == 0){
                    printf("|            |    << %d >>   ",score);
                }
                else if(score / 10000 == 0){
                    printf("|            |   << %d >>   ",score);
                }
            }
            if ((j == 23)&&(i == 79)){
                    printf("            |________________|");
            }
        }
    printf("\n");
    }
}

int gameover_sensor(char game[80][30]){
    int ai_gameover_sensor = 0;
    for (int i = 41; i < 79; i++){
        if (game[i][1] != 32){return 1;}
    }
return 0;
}

int score_sensor(char game[80][30] , int score_level){
    int level = 0;
    int j = 2;
    while ( j < 29 ){
        for (int i = 41; i < 79; i++){
            if (game[i][j] == 32){level ++;}
        }
        if (level == 0){return j;}
        level = 0;
        j++;
    }
    return 0;
}

void score_delete(char game[80][30] , int score_level){
    char copy_game[80][30];
    for (int j = 0; j < 29; j++){
        for (int i = 41; i < 79; i++){
            copy_game[i][j] = game[i][j];
        }
    }
    // if (score_level == 28)
    for (int j = score_level; j > 0; j--){
        for (int i = 41; i < 79; i++){
            game[i][j] = copy_game[i][j-1];
        }
    }
}

int sign_gameover(){
    system("color 0C");
    system("color C0");
    system("color 0C");
    printf("                                                                                                                 \n  ");
    printf("                                                                                                                 \n  ");
    printf("        << <<         #####   #####  ##     ##  #####        #####  #      #  #####  #####          >> >>        \n  ");
    printf("      << <<          #        #   #  # #   # #  #           #     #  #    #   #      #    #           >> >>      \n  ");
    printf("    << <<            #   ###  #####  #  # #  #  #####       #     #  #    #   #####  #####              >> >>    \n  ");
    printf("      << <<          #     #  #   #  #   #   #  #           #     #   #  #    #      #  #             >> >>      \n  ");
    printf("        << <<         #####   #   #  #       #  #####        #####     ##     #####  #   ##         >> >>        \n  ");
    printf("                                                                                                                 \n  ");
    printf("                                     << Enter key [Enter] to play again >>                                       \n  ");
    printf("                                                                                                                 \n  ");
    printf("                                         << Enter key [Esc] to exit >>                                           \n  ");
    char ch1;
    char ch2;
	while (1) {
		if (kbhit) {
			ch1 = getch();
			if ((int)ch1 == 13){
                system("color 0F");
                return 0;
			}else if((int)ch1 == 27){
				system("color 0F");
                return 1;
			}else{printf("You have entered : %c\n", ch1);}
		}
	}
}