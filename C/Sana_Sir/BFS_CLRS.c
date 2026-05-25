#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF 999999  
#define NIL -1

typedef enum { WHITE, GRAY, BLACK } Color;

// Global variables to avoid pointers
int adjMatrix[MAX_VERTICES][MAX_VERTICES];
Color color[MAX_VERTICES];
int d[MAX_VERTICES];
int pi[MAX_VERTICES];
int V; 

// Queue setup
int queue[MAX_VERTICES];
int front = 0;
int rear = 0;

void enqueue(int vertex) {
    queue[rear] = vertex;
    rear++;
}

int dequeue() {
    int vertex = queue[front];
    front++;
    return vertex;
}

bool isQueueEmpty() {
    return front == rear;
}

// --- CLRS BFS Algorithm ---
void BFS(int s) {
    for (int u = 0; u < V; u++) {
        if (u != s) {
            color[u] = WHITE;
            d[u] = INF;
            pi[u] = NIL;
        }
    }

    color[s] = GRAY;
    d[s] = 0;
    pi[s] = NIL;

    front = 0;
    rear = 0;
    enqueue(s);

    while (!isQueueEmpty()) {
        int u = dequeue();

        for (int v = 0; v < V; v++) {
            if (adjMatrix[u][v] == 1 && color[v] == WHITE) {
                color[v] = GRAY;
                d[v] = d[u] + 1;
                pi[v] = u;
                enqueue(v);
            }
        }
        color[u] = BLACK;
    }
}

// --- Helper to visually print the path ---
void printPath(int current_vertex) {
    if (pi[current_vertex] == NIL) {
        printf("%d", current_vertex);
        return;
    }
    printPath(pi[current_vertex]);
    printf(" -> %d", current_vertex);
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter the Adjacency Matrix (%d x %d):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    int source;
    printf("Enter the source vertex (0 to %d): ", V - 1);
    scanf("%d", &source);

    // Run BFS
    BFS(source);

    // --- Clean, Easy-to-Understand Output ---
    printf("\n=========================================\n");
    printf("          BFS SEARCH RESULTS\n");
    printf("=========================================\n");
    printf("Starting Source Node: %d\n\n", source);

    for (int i = 0; i < V; i++) {
        printf("● Destination Node %d:\n", i);
        
        if (d[i] == INF) {
            printf("  Status: Unreachable from source.\n");
        } else {
            printf("  Distance: %d steps away\n", d[i]);
            printf("  Path taken: ");
            printPath(i);
            printf("\n");
        }
        printf("-----------------------------------------\n");
    }

    return 0;
}