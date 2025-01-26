
#include "graph.h"
#include "queue.h"


int main()
{
    Graph *graph = readFile("graph.txt");

    bfs(graph, graph->vertexs[0]);

    calculateWeight(graph);

    unreacheableNodes(graph);

    freeGraph(graph);

    return 0;
}