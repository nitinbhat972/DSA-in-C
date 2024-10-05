#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTEX 100

typedef struct Graph {
    int vertex, arr[MAX_VERTEX][MAX_VERTEX];
} *graph;

// Function to create a graph with 'v' vertices
graph createGraph(int v) {
    graph g = malloc(sizeof(struct Graph));
    g->vertex = v;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            g->arr[i][j] = 0;
        }
    }
    return g;
}

// Function to create an edge between vertices 'i' and 'j' in the graph
void createEdge(graph g, int i, int j) {
    g->arr[i][j] = 1;
    g->arr[j][i] = 1; // for undirected graph
}

// Breadth-First Search traversal of the graph
void bfs(graph g, int startingNode, int visited[]) {
    int queue[MAX_VERTEX], front = -1, rear = -1;

    visited[startingNode] = 1;
    queue[++rear] = startingNode;
    printf("%d ", startingNode);

    while (front != rear) {
        int currentNode = queue[++front];
        for (int i = 0; i < g->vertex; i++) {
            if (g->arr[currentNode][i] && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
                printf("%d ", i);
            }
        }
    }
}

// Depth-First Search traversal of the graph using iteration
void dfsIter(graph g, int startingNode, int visited[]) {
    int stack[MAX_VERTEX], top = -1;

    visited[startingNode] = 1;
    stack[++top] = startingNode;

    while (top != -1) {
        int currentNode = stack[top--];
        printf("%d ", currentNode);
        for (int i = 0; i < g->vertex; i++) {
            if (g->arr[currentNode][i] && !visited[i]) {
                visited[i] = 1;
                stack[++top] = i;
            }
        }
    }
}

// Depth-First Search traversal of the graph using recursion
void dfsRec(graph g, int startingNode, int visited[]) {
    if (!visited[startingNode]) {
        visited[startingNode] = 1;
        printf("%d ", startingNode);
    }
    for (int i = 0; i < g->vertex; i++) {
        if (g->arr[startingNode][i] && !visited[i]) {
            dfsRec(g, i, visited);
        }
    }
}

int main() {
    graph g = createGraph(4);
    int visited[MAX_VERTEX] = {0};
    createEdge(g, 0, 1);
    createEdge(g, 0, 2);
    createEdge(g, 1, 2);
    createEdge(g, 2, 3);

    // Uncomment the desired traversal method
    // bfs(g, 0, visited);
    // dfsRec(g, 0, visited);
    // dfsIter(g, 0, visited);

    // For a segmented graph
    // for (int i = 0; i < g->vertex; i++) {
        // if(!visited[i]){//is the current node is not visited make it the startine node
            // bfs(g, i, visited); // Changing the starting node at every iteration
            // dfsRec(g, i, visited);
            // dfsIter(g, i, visited);
        // }
    // }


    return 0;
}
