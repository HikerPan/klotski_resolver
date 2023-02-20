/*
 * @Author: hikerpan 
 * @Date: 2023-02-20 15:40:05
 * @LastEditors: hikerpan
 * @LastEditTime: 2023-02-20 16:31:52
 * @FilePath: \klotski_resolver\queue.h
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name}, All Rights Reserved. 
 */
#ifndef QUEUE_H
#define QUEUE_H

#include "position.h"

typedef struct queue
{
    POSITION *arr;
    int front;
    int rear;
} QUEUE;

int is_full(struct queue *q);
int is_empty(struct queue *q);
int add(struct queue *q, POSITION value);
int get(struct queue *q, POSITION *value);

#endif // QUEUE_H
