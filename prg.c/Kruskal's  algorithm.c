#include <stdio.h>
#include <stdlib.h>

#define MAX 9
#define INFINITY 999

int cost[MAX][MAX], parent[MAX];
int n; // Number of vertices

// Find function for Union-Find
int find(int i) {
    while (parent[i]) {
        i = parent[i];
    }
    return i;
}

// Union function for Union-Find
int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int i, j, a, b, u, v, ne = 1, min, mincost = 0;

    printf("\nImplementation of Kruskal's algorithm\n");
    printf("Enter the number of vertices (max %d): ", MAX - 1);
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (0 for no edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = INFINITY;  // No edge
            }
        }
    }

    // Initialize parent array to zero
    for (i = 1; i <= n; i++) {
        parent[i] = 0;
    }

    printf("The edges of Minimum Cost Spanning Tree are:\n");
    while (ne < n) {
        min = INFINITY;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (uni(u, v)) {
            printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = INFINITY;
    }

    printf("\nMinimum cost = %d\n", mincost);
    return 0;
}