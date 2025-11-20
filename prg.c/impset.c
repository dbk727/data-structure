#include <stdio.h>

int main() {
    int i;
    int U[5] = {1, 2, 3, 4, 5};
    int A[5] = {1, 0, 0, 1, 1};
    int B[5] = {0, 1, 1, 1, 0};
    int uni[5], inter[5], diffA[5], diffB[5], compA[5], compB[5];

    printf("\nUniversal set is { ");
    for (i = 0; i < 5; i++) {
        printf("%d ", U[i]);
    }
    printf("}\n");

    printf("\nSet A = { ");
    for (i = 0; i < 5; i++) {
        if (A[i] == 1) {
            printf("%d ", U[i]);
        }
    }
    printf("}\n");

    printf("Set B = { ");
    for (i = 0; i < 5; i++) {
        if (B[i] == 1) {
            printf("%d ", U[i]);
        }
    }
    printf("}\n");


    printf("\nUnion (bit representation): ");
    for (i = 0; i < 5; i++) {
        uni[i] = A[i] | B[i];
        printf("%d", uni[i]);
    }

    printf("\nUnion (elements): { ");
    for (i = 0; i < 5; i++) {
        if (uni[i] == 1)
            printf("%d ", U[i]);
    }
    printf("}\n");

    
    printf("\nIntersection (bit representation): ");
    for (i = 0; i < 5; i++) {
        inter[i] = A[i] & B[i];
        printf("%d", inter[i]);
    }

    printf("\nIntersection (elements): { ");
    for (i = 0; i < 5; i++) {
        if (inter[i] == 1)
            printf("%d ", U[i]);
    }
    printf("}\n");

 
    printf("\nComplement of A (bit representation): ");
    for (i = 0; i < 5; i++) {
        compA[i] = !A[i];
        printf("%d", compA[i]);
    }

    printf("\nComplement of A (elements): { ");
    for (i = 0; i < 5; i++) {
        if (compA[i] == 1)
            printf("%d ", U[i]);
    }
    printf("}\n");

    
    printf("\nComplement of B (bit representation): ");
    for (i = 0; i < 5; i++) {
        compB[i] = !B[i];
        printf("%d", compB[i]);
    }

    printf("\nComplement of B (elements): { ");
    for (i = 0; i < 5; i++) {
        if (compB[i] == 1)
            printf("%d ", U[i]);
    }
    printf("}\n");

   
    printf("\nA - B (bit representation): ");
    for (i = 0; i < 5; i++) {
        diffA[i] = A[i] & compB[i];
        printf("%d", diffA[i]);
    }

    printf("\nA - B (elements): { ");
    for (i = 0; i < 5; i++) {
        if (diffA[i] == 1)
            printf("%d ", U[i]);
    }
    printf("}\n");

    
    printf("\nB - A (bit representation): ");
    for (i = 0; i < 5; i++) {
        diffB[i] = B[i] & compA[i];
        printf("%d", diffB[i]);
    }

    printf("\nB - A (elements): { ");
    for (i = 0; i < 5; i++) {
        if (diffB[i] == 1)
            printf("%d ", U[i]);
    }
    printf("}\n");

    return 0;
}

