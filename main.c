/*
 * @Author: hikerpan 
 * @Date: 2023-02-20 15:40:05
 * @LastEditors: hikerpan
 * @LastEditTime: 2023-02-20 17:21:58
 * @FilePath: \klotski_resolver\main.c
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name}, All Rights Reserved. 
 */

#include "position.h"
#include "queue.h"

void bfs(POSITION root, int max_depth);
 
int main()
{
    POSITION root =
    {
        {   { 2, 4, 4, 2},
            { 2, 4, 4, 2},
            { 2, 3, 3, 2},
            { 2, 1, 1, 2},
            { 1, 0, 0, 1}
        },
        {   {1, 2, 2, {{0, 0}, {0, 1}}},
            {2, 4, 4, {{1, 0}, {2, 0}, {1, 1}, {2, 1}}},
            {3, 2, 2, {{3, 0}, {3, 1}}},
            {4, 2, 2, {{0, 2}, {0, 3}}},
            {5, 3, 2, {{1, 2}, {2, 2}}},
            {6, 2, 2, {{3, 2}, {3, 3}}},
            {7, 1, 1, {{1, 3}}},
            {8, 1, 1, {{2, 3}}},
            {9, 1, 1, {{0, 4}}},
            {10, 1, 1, {{3, 4}}}
        }, NULL
    };

    bfs(root, 200);

    return 0;
}

/**
 * @description: 
 * @param {POSITION} root
 * @param {int} max_depth
 * @return {*}
 */
void bfs(POSITION root, int max_depth)
{
    QUEUE q = { NULL, -1, 0 };
    q.arr = malloc(MAX * sizeof(POSITION));

    POSITION u;
    add(&q, root);
    add_to_visited(&root);

    int n, real_n;
    int current_depth = 0;
    int elements_till_next_level = 1;
    int elements_for_next_level = 0;

    while(get(&q, &u))
    {
        if(is_good(&u))
        {
            printf("Success!!\n");
            print_solution(&u);
            free(q.arr);
            exit(0);
        }

        POSITION *arr = all_neighbours(&u, &n);
        real_n  = 0;
        for(int i = 0; i < n; i++)
        {
            if(!is_visited(&arr[i]))
            {
                arr[i].parent = &q.arr[q.front - 1];
                add(&q, arr[i]);
                add_to_visited(&arr[i]);
                real_n++;
            }
        }
        free(arr);
        elements_for_next_level += real_n;
        if(--elements_till_next_level == 0)
        {
            if(++current_depth > max_depth)
                return;
            printf("Current level: %d\n", current_depth);
            printf("New positions for level: %d\n", elements_for_next_level);
            elements_till_next_level = elements_for_next_level;
            elements_for_next_level = 0;
        }
    }
}
