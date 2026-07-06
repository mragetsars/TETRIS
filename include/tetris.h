#ifndef TETRIS_H
#define TETRIS_H

#define TETRIS_SCREEN_WIDTH 80
#define TETRIS_SCREEN_HEIGHT 30
#define TETRIS_SHAPE_ROWS 5
#define TETRIS_COORDINATES 2
#define TETRIS_INITIAL_NEXT_SHAPE 4
#define TETRIS_INITIAL_FALL_SPEED_MS 200
#define TETRIS_MIN_FALL_SPEED_MS 50
#define TETRIS_SPEED_STEP_MS 50
#define TETRIS_SCORE_PER_ROW 20

int show_tetris_sign(void);
int show_gameover_sign(void);

void table_generator(char game[TETRIS_SCREEN_WIDTH][TETRIS_SCREEN_HEIGHT]);
int random_shape(void);
void shape_generator(
    int shape[TETRIS_SHAPE_ROWS][TETRIS_COORDINATES],
    int shape_shadow[TETRIS_SHAPE_ROWS][TETRIS_COORDINATES],
    int next_shape
);

int shift_left(
    int shape[TETRIS_SHAPE_ROWS][TETRIS_COORDINATES],
    int shape_shadow[TETRIS_SHAPE_ROWS][TETRIS_COORDINATES]
);
int shift_right(
    int shape[TETRIS_SHAPE_ROWS][TETRIS_COORDINATES],
    int shape_shadow[TETRIS_SHAPE_ROWS][TETRIS_COORDINATES]
);
int shift_down(
    int shape[TETRIS_SHAPE_ROWS][TETRIS_COORDINATES],
    int shape_shadow[TETRIS_SHAPE_ROWS][TETRIS_COORDINATES]
);
int space_rotate(
    int shape[TETRIS_SHAPE_ROWS][TETRIS_COORDINATES],
    int shape_shadow[TETRIS_SHAPE_ROWS][TETRIS_COORDINATES]
);

int game_updater(
    char game[TETRIS_SCREEN_WIDTH][TETRIS_SCREEN_HEIGHT],
    int shape[TETRIS_SHAPE_ROWS][TETRIS_COORDINATES],
    int shape_shadow[TETRIS_SHAPE_ROWS][TETRIS_COORDINATES]
);
void print_game(
    char game[TETRIS_SCREEN_WIDTH][TETRIS_SCREEN_HEIGHT],
    int score,
    int next_shape
);

int gameover_sensor(char game[TETRIS_SCREEN_WIDTH][TETRIS_SCREEN_HEIGHT]);
int score_sensor(char game[TETRIS_SCREEN_WIDTH][TETRIS_SCREEN_HEIGHT]);
void score_delete(
    char game[TETRIS_SCREEN_WIDTH][TETRIS_SCREEN_HEIGHT],
    int score_level
);

#endif
