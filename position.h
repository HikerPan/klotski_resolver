/*
 * @Author: hikerpan 
 * @Date: 2023-02-20 15:40:05
 * @LastEditors: hikerpan
 * @LastEditTime: 2023-02-20 16:32:24
 * @FilePath: \klotski_resolver\position.h
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name}, All Rights Reserved. 
 */

#ifndef POSITION_H
#define POSITION_H

#define BLOCKS_IN_PIECE 4
#define PIECES_IN_POSITION 10
#define MAX_POSSIBLE_NEIGHBOURS 10

#define MAX 65536

#define BOARD_Y 5
#define BOARD_X 4

#include <stdio.h>
#include <stdlib.h>

typedef struct block
{
    signed char x, y;
} BLOCK;

typedef struct piece
{
    unsigned char id; //unique id (each piece has its own id)
    unsigned char mat_id; //size id (pieces of the same size have the same mat_id)
    unsigned char n; //number of blocks in piece
    BLOCK blocks[BLOCKS_IN_PIECE];
} PIECE;

typedef struct position
{
    unsigned char mat[BOARD_Y][BOARD_X];
    PIECE pieces[PIECES_IN_POSITION];
    struct position *parent;
} POSITION;

int is_good(POSITION *pos);
void print_position(POSITION *pos);
int is_visited(POSITION *pos);
void add_to_visited(POSITION *pos);
POSITION * all_neighbours(POSITION *p, int *n);
BLOCK right (BLOCK b);
BLOCK left (BLOCK b);
BLOCK down (BLOCK b);
BLOCK up (BLOCK b);
POSITION move_piece(POSITION *pos, PIECE *p, BLOCK (*d) (BLOCK));
void matrix_from_pieces(POSITION *pos);
int can_move(POSITION *pos, PIECE *piece, BLOCK (*d) (BLOCK));
int is_block_in_range(BLOCK b);
int is_block_in_any_piece(BLOCK b, POSITION *p);
int is_block_in_piece(BLOCK b, PIECE *p);
void print_solution(POSITION *p);

#endif // POSITION_H
