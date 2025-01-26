#ifndef TYPE_H
#define TYPE_H

#include <stdbool.h>


typedef struct Node
{
    int vertex;
    int weight;
    struct Node *next;

} Node;

typedef struct Graph
{
    int noOfVertex;
    bool isDirected;
    char *vertexs;
    Node **adjList;
    int *visited;
} Graph;

Node *createNode(int vertex, int weight);
Graph *createGraph(int noOfVertex, bool isDirected, char *vertexs);
int getVertexIndex(Graph *graph, char vertex);
void addEdge(Graph *graph, char one, char two, int weight);
void bfs(Graph *graph, char startNode);
void calculateWeight(Graph *graph);
void unreacheableNodes(Graph *graph);
void freeGraph(Graph *graph);
Graph *readFile(char *filename);

#endif
