#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "graph.h"
#include "queue.h"


int getVertexIndex(Graph *graph, char vertex)
{
    for (int i = 0; i < graph->noOfVertex; i++)
    {
        if (graph->vertexs[i] == vertex)
        {
            return i;
        }
    }
}

Graph *createGraph(int noOfVertex, bool isDirected, char *vertexs)
{
    Graph *newGraph = (Graph *)malloc(sizeof(Graph));
    newGraph->noOfVertex = noOfVertex;
    newGraph->adjList = (Node **)malloc(sizeof(Node *) * noOfVertex);
    newGraph->visited = (int *)malloc(noOfVertex * sizeof(int));
    newGraph->isDirected = isDirected;
    newGraph->vertexs = (char *)malloc(noOfVertex * sizeof(char));
    for (int i = 0; i < noOfVertex; i++)
    {
        newGraph->adjList[i] = NULL;
        newGraph->visited[i] = 0;
        newGraph->vertexs[i] = vertexs[i];
    }

    return newGraph;
}

Node *createNode(int vertex, int weight)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;

    return newNode;
}

void addEdge(Graph *graph, char node1, char node2, int weight)
{
    int nodeIndex1 = getVertexIndex(graph, node1);
    int nodeIndex2 = getVertexIndex(graph, node2);
    Node *newNode = createNode(nodeIndex2, weight);
    newNode->next = graph->adjList[nodeIndex1];
    graph->adjList[nodeIndex1] = newNode;

    if (!graph->isDirected)
    {

        Node *newNode1 = createNode(nodeIndex1, weight);
        newNode1->next = graph->adjList[nodeIndex2];
        graph->adjList[nodeIndex2] = newNode1;
    }
}

void bfs(Graph *graph, char startVertexLetter)
{
    int startVertex = getVertexIndex(graph, startVertexLetter);

    Queue *q = createQueue(graph->noOfVertex);
    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    printf("BFS Traversal Path: ");

    while (!isEmpty(q))
    {
        int currentVertex = dequeue(q);
        printf("%c", graph->vertexs[currentVertex]);

        Node *temp = graph->adjList[currentVertex];
        while (temp)
        {
            int vertex = temp->vertex;

            if (!graph->visited[vertex])
            {
                graph->visited[vertex] = 1;
                enqueue(q, vertex);
            }

            temp = temp->next;
        }
        if (!isEmpty(q))
        {
            printf(" -> ");
        }
    }
    printf("\n");

    freeQueue(q);
}

void calculateWeight(Graph *graph)
{
    int totalWeight = 0;
    for (int i = 0; i < graph->noOfVertex; i++)
    {
        Node *temp = graph->adjList[i];
        while (temp)
        {

            totalWeight += temp->weight;
            temp = temp->next;
        }
    }

    if (!graph->isDirected)
    {
        totalWeight = totalWeight / 2;
    }

    printf("Total Weight: %d \n", totalWeight);
}

void unreacheableNodes(Graph *graph)
{
    bool isUnreacheable = 0;
    printf("Unreacheable Nodes: ");
    for (int i = 0; i < graph->noOfVertex; i++)
    {
        if (graph->visited[i] == 0)
        {
            printf("%c  ", graph->vertexs[i]);
            isUnreacheable = 1;
        }
    }

    if (!isUnreacheable)
    {
        printf("None");
    }
    printf("\n");
}

Graph *readFile(char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return NULL;
    }

    int noOfVertex;
    char graphType[20];
    bool isDirected;
    char node1, node2;
    int weight;

    fscanf(file, "%d", &noOfVertex);
    char vertexs[noOfVertex];

    for (int i = 0; i < noOfVertex; i++)
    {
        fscanf(file, " %c", &vertexs[i]);
    }

    fscanf(file, "%s", graphType);
    if (strcmp(graphType, "directed") == 0)
    {
        isDirected = 1;
    }
    else
    {
        isDirected = 0;
    };

    Graph *graph = createGraph(noOfVertex, isDirected, vertexs);

    while (fscanf(file, " %c %c %d", &node1, &node2, &weight) == 3)
    {
        addEdge(graph, node1, node2, weight);
    }

    fclose(file);

    return graph;
}


void freeGraph(Graph *graph)
{
    if (graph)
    {
        if (graph->adjList)
        {
            for (int i = 0; i < graph->noOfVertex; i++)
            {
                Node *temp = graph->adjList[i];
                while (temp)
                {
                    Node *next = temp->next;
                    free(temp);
                    temp = next;
                }
            }
            free(graph->adjList);
        }

        if (graph->visited)
        {
            free(graph->visited);
        }

        free(graph);
    }
}