#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queue.h"



Queue *createQueue(int noOfVertex)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->vertex = (int *)malloc(sizeof(int) * noOfVertex);
    q->front = 0;
    q->rear = 0;
    q->noOfVertex = noOfVertex;

    return q;
}

bool isEmpty(Queue *q)
{
    if (q->front == q->rear)
    {
        return 1;
    }
    return 0;
}

bool isFull(Queue *q)
{
    if (q->rear == q->noOfVertex)
    {
        return 1;
    }
    return 0;
}
void enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is Full\n");
    }
    else
    {

        q->vertex[q->rear] = value;
        q->rear++;
    }
}

int dequeue(Queue *q)
{
    int vertex;
    if (isEmpty(q))
    {
        printf("Queue is Empty");
        return -1;
    }
    else
    {
        vertex = q->vertex[q->front];
        q->front++;
    }

    return vertex;
}

void freeQueue(Queue *q)
{
    if (q)
    {
        if (q->vertex)
        {
            free(q->vertex);
        }
        free(q);
    }
}