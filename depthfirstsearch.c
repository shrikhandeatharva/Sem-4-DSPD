#include <stdio.h>
#include <stdlib.h>

// Graph class represents a directed graph
// using adjacency list representation
struct Graph {
    int numVertices;
    int* visited;
    int** adjMatrix;
};

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->visited = (int*)malloc(vertices * sizeof(int));
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));

    int i, j;
    for (i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
        graph->visited[i] = 0;
        for (j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
}

// DFS traversal of the vertices reachable from v
void DFS(struct Graph* graph, int v) {
    printf("%d ", v);
    graph->visited[v] = 1;

    int i;
    for (i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[v][i] && !graph->visited[i]) {
            DFS(graph, i);
        }
    }
}

// Driver's code
int main() {
    // Create a graph with 4 vertices
    struct Graph* graph = createGraph(4);

    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    printf("Following is Depth First Traversal (starting from vertex 2):\n");
    DFS(graph, 2);

    return 0;
}
