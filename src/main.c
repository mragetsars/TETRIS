#include "console.h"
#include "tetris.h"

#include <stdio.h>
#include <stdlib.h>

static int run_game(void)
{
    console_configure();

    if (show_tetris_sign()) {
        return 0;
    }

    console_clear();

    char game[TETRIS_SCREEN_WIDTH][TETRIS_SCREEN_HEIGHT];
    int shape[TETRIS_SHAPE_ROWS][TETRIS_COORDINATES];
    int shape_shadow[TETRIS_SHAPE_ROWS][TETRIS_COORDINATES];

    int score = 0;
    int next_shape = TETRIS_INITIAL_NEXT_SHAPE;
    int score_level = 0;
    int fall_speed = TETRIS_INITIAL_FALL_SPEED_MS;

    table_generator(game);
    shape_generator(shape, shape_shadow, next_shape);
    next_shape = random_shape();
    game_updater(game, shape, shape_shadow);
    print_game(game, score, next_shape);

    while (1) {
        while (!console_kbhit()) {
            if (shift_down(shape, shape_shadow) && game_updater(game, shape, shape_shadow)) {
                print_game(game, score, next_shape);
            } else {
                fall_speed = TETRIS_INITIAL_FALL_SPEED_MS;
                shape_generator(shape, shape_shadow, next_shape);
                next_shape = random_shape();

                while ((score_level = score_sensor(game)) != 0) {
                    print_game(game, score, next_shape);
                    console_flash_background("A0", 100);
                    score += TETRIS_SCORE_PER_ROW;
                    score_delete(game, score_level);
                    print_game(game, score, next_shape);
                }
            }

            if (gameover_sensor(game)) {
                return show_gameover_sign() ? 0 : 1;
            }

            console_sleep_ms((unsigned int)fall_speed);
        }

        int ch = console_getch();

        if (ch == 'a' || ch == 'A') {
            if (shift_left(shape, shape_shadow) && game_updater(game, shape, shape_shadow)) {
                print_game(game, score, next_shape);
            }
        } else if (ch == 'd' || ch == 'D') {
            if (shift_right(shape, shape_shadow) && game_updater(game, shape, shape_shadow)) {
                print_game(game, score, next_shape);
            }
        } else if (ch == 's' || ch == 'S') {
            if (fall_speed > TETRIS_MIN_FALL_SPEED_MS) {
                fall_speed -= TETRIS_SPEED_STEP_MS;
            }
        } else if (ch == ' ') {
            if (space_rotate(shape, shape_shadow) && game_updater(game, shape, shape_shadow)) {
                print_game(game, score, next_shape);
            }
        } else if (ch == 'p' || ch == 'P') {
            console_set_color("0E");
            console_pause();
            console_set_color("0F");
        } else if (ch == 27) {
            return show_gameover_sign() ? 0 : 1;
        } else {
            console_set_color("6E");
            printf("You have entered: %c\nPlease pay attention to the guide.\n", ch);
            console_set_color("0F");
            console_pause();
        }
    }
}

int main(void)
{
    while (run_game()) {
        /* Restart requested by the game-over dialog. */
    }

    return EXIT_SUCCESS;
}
