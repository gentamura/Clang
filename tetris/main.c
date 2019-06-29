#include <stdio.h>
#include <stdlib.h>
#include <gconio.h>

#define BLOCK_HEIGHT 4
#define BLOCK_WIDTH 4

#define FIELD_HEIGHT 21
#define FIELD_WIDTH 12

void my_init_var(void);
void my_make_block(void);
void my_make_field(void);
void my_init_field(void);
void my_draw_field(void);
void my_clear_field(void);

int block[BLOCK_WIDTH][BLOCK_HEIGHT];
int stage[FIELD_WIDTH][FIELD_HEIGHT];
int field[FIELD_WIDTH][FIELD_HEIGHT];

int blocks[4][4] = {
  {0, 0, 0, 0},
  {0, 1, 1, 0},
  {0, 1, 1, 0},
  {0, 0, 0, 0}
};

int fall;
int side;

int main() {
  int stop;

  my_init_var();

  for (fall = 0; fall < 18; fall++) {
    my_make_block();
    my_make_field();
    my_init_field();
    my_draw_field();
    my_clear_field();

    stop = getch();
  }
  return 0;
}

void my_init_var() {
  fall = 0;
  side = 4;
}

void my_make_block() {
  int x, y;
  for (y = 0; y < 4; y++) {
    for (x = 0; x < 4; x++) {
      block[y][x] = blocks[y][x];
    }
  }
}

void my_make_field() {
  int i, j, x, y;
  for (y = 0; y < BLOCK_HEIGHT; y++) {
    for (x = 0; x < BLOCK_WIDTH; x++) {
      field[y + fall][x + side] = block[y][x];
    }
  }
  for (i = 0; i < FIELD_HEIGHT; i++) {
    for (j = 0; j < FIELD_WIDTH; j++) {
      field[i][j] = field[i][j] + stage[i][j];
    }
  }
}

void my_init_field() {
  int i, j;
  for (i = 0; i < 21; i++) {
    for (j = 0; j < 12; j++) {
      field[i][0] = 9;
      field[20][j] = 9;
      field[i][11] = 9;
    }
  }
}

void my_draw_field() {
  int i, j;
  system("clear");
  for (i = 0; i < 21; i++) {
    for (j = 0; j < 12; j++) {
      if (field[i][j] == 9) {
        printf("9");
      } else if (field[i][j] == 1) {
        printf("1");
      } else {
        printf("0");
      }
    }
    printf("\n"); 
  }
}

void my_clear_field() {
  int i, j;
  for (i = 0; i < FIELD_HEIGHT; i++) {
    for (j = 0; j < FIELD_WIDTH; j++) {
      field[i][j] = 0;
    }
  }
}
