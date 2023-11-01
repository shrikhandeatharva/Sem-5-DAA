#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Edge {
    char source, destination;
    int weight;
};

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

int main() {
    int V = 5; // Number of vertices
    int numEdges = 7; // Number of edges
    int w = 0;

    // struct Edge edges[] = {
    //     {'A', 'B', 8},
    //     {'B', 'C', 7},
    //     {'A', 'I', 4},
    //     {'I', 'G', 8},
    //     {'G', 'A', 11},
    //     {'G', 'H', 7},
    //     {'G', 'F', 1},
    //     {'B', 'H', 2},
    //     {'H', 'F', 6},
    //     {'B', 'E', 4},
    //     {'F', 'E', 2},
    //     {'C', 'E', 14},
    //     {'C', 'D', 9},
    //     {'E', 'D', 10},
    // };

    struct Edge edges[] = {
       {'A', 'B', 1},
       {'B', 'C', 3},
       {'A', 'C', 7},
       {'A', 'D', 4},
       {'C', 'D', 2},
       {'A', 'E', 5},
       {'E', 'D', 6},
    };

    // Sort the edges using qsort
    qsort(edges, numEdges, sizeof(struct Edge), compareEdges);

    int parent[26]; // Assuming a maximum of 26 vertices (A-Z)
    for (int i = 0; i < 26; i++) {
        parent[i] = -1;
    }

    printf("Edges in the minimal spanning tree are as follows: ");

    for (int i = 0; i < numEdges; i++) {
        struct Edge currentEdge = edges[i];
        int x = currentEdge.source - 'A';
        int y = currentEdge.destination - 'A';

        while (parent[x] != -1) {
            x = parent[x];
        }

        while (parent[y] != -1) {
            y = parent[y];
        }

        if (x != y) {
            parent[y] = x;
            w += currentEdge.weight;
            if (i > 0) {
                printf("-> ");
            }
            printf("(%c, %c, %d)", currentEdge.source, currentEdge.destination, currentEdge.weight);
        }
    }

    printf("-> NULL\n");
    printf("Total weight: %d\n", w);

    return 0;
}
