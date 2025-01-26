#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include "graph.h"

typedef struct Queue
{
    int *vertex;
    int front;
    int rear;
    int noOfVertex;
} Queue;

Queue *createQueue(int noOfVertex);
bool isEmpty(Queue *q);
bool isFull(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
void freeQueue(Queue *q);


#endif