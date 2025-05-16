#include <stdio.h>

#define V 4
#define INF 1000

void floydWarshall(int graph[V][V]) {
    int dist[V][V], i, j, k;

    // Initialize the solution matrix same as the input graph matrix
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Add all vertices one by one to the set of intermediate vertices
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printf("Shortest distances between every pair of vertices:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {0,   9,  -4, INF},
        {6, 0,  INF, 2},
        {INF, 5, 0,   INF},
        {INF, INF, 1, 0}
    };

    floydWarshall(graph);
    return 0;
}