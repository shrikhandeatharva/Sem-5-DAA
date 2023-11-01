#include <stdio.h>
#include <limits.h>

#define V 9
#define E 14

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Function to print the distance array
void printDistances(int dist[], int n) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

// Bellman-Ford algorithm to find the shortest paths from a source vertex
void bellmanFord(struct Edge graph[], int src) {
    int dist[V];

    // Initialize distance array
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    // Relax all edges |V| - 1 times
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph[j].src;
            int v = graph[j].dest;
            int weight = graph[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < E; i++) {
        int u = graph[i].src;
        int v = graph[i].dest;
        int weight = graph[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains a negative-weight cycle\n");
            return;
        }
    }

    // Print the distance array
    printDistances(dist, V);
}

int main() {
    struct Edge graph[E] = {
        {0, 1, 4}, {0, 7, 8}, {1, 2, 8}, {1, 7, 11},
        {2, 3, 7}, {2, 8, 2}, {2, 5, 4}, {3, 4, 9},
        {3, 5, 14}, {4, 5, 10}, {5, 6, 2}, {6, 7, 1},
        {6, 8, 6}, {7, 8, 7}
    };

    bellmanFord(graph, 0);

    return 0;
}
