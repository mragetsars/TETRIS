#include "tetris.h"

#include <assert.h>
#include <stdio.h>

static void test_table_generation(void)
{
    char game[TETRIS_SCREEN_WIDTH][TETRIS_SCREEN_HEIGHT];

    table_generator(game);

    assert(game[40][0] == '|');
    assert(game[79][0] == '|');
    assert(game[41][29] == 'T');
    assert(game[78][29] == 'T');
    assert(game[41][1] == ' ');
}

static void test_shape_generation_and_update(void)
{
    char game[TETRIS_SCREEN_WIDTH][TETRIS_SCREEN_HEIGHT];
    int shape[TETRIS_SHAPE_ROWS][TETRIS_COORDINATES];
    int shape_shadow[TETRIS_SHAPE_ROWS][TETRIS_COORDINATES];

    table_generator(game);
    shape_generator(shape, shape_shadow, 0);

    assert(shape[4][0] == 0);
    assert(game_updater(game, shape, shape_shadow) == 1);
    assert(game[59][1] == '[');
    assert(game[60][1] == ']');
    assert(game[61][1] == '[');
    assert(game[62][1] == ']');
    assert(gameover_sensor(game) == 1);
}

static void test_basic_movement(void)
{
    int shape[TETRIS_SHAPE_ROWS][TETRIS_COORDINATES];
    int shape_shadow[TETRIS_SHAPE_ROWS][TETRIS_COORDINATES];

    shape_generator(shape, shape_shadow, 1);

    int original_x = shape[0][0];
    int original_y = shape[0][1];

    assert(shift_left(shape, shape_shadow) == 1);
    assert(shape[0][0] == original_x - 2);
    assert(shape_shadow[0][0] == original_x);

    assert(shift_right(shape, shape_shadow) == 1);
    assert(shape[0][0] == original_x);

    assert(shift_down(shape, shape_shadow) == 1);
    assert(shape[0][1] == original_y + 1);
}

static void test_score_detection_and_deletion(void)
{
    char game[TETRIS_SCREEN_WIDTH][TETRIS_SCREEN_HEIGHT];

    table_generator(game);

    for (int i = 41; i < 79; i++) {
        game[i][28] = '#';
    }

    assert(score_sensor(game) == 28);
    score_delete(game, 28);
    assert(score_sensor(game) == 0);
}

int main(void)
{
    test_table_generation();
    test_shape_generation_and_update();
    test_basic_movement();
    test_score_detection_and_deletion();

    puts("All Tetris logic smoke tests passed.");
    return 0;
}
