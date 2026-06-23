#include <stdlib.h>

int compare(const void *a, const void *b) {
    const int* rowA = *(const int**)a;
    const int* rowB = *(const int**)b;
    if (rowA[0] < rowB[0]) return -1;
    if (rowA[0] > rowB[0]) return 1;
    return 0;
}

int** create_copy(const int* const* points, const int pointsSize, const int* pointsColSIze) {

    int** copy = malloc(pointsSize * sizeof(int*));
    if (copy == NULL) {
        return NULL;
    }

    for (int i = 0; i < pointsSize; i++) {

        copy[i] = (int*)malloc(pointsColSIze[i] * sizeof(int));
        if (copy[i] == NULL) {
            for (int k = 0; k < i; k++) {
                free(copy[k]);
            }
            free(copy);
            return NULL;
        }

        for (int j = 0; j < pointsColSIze[0]; j++) {
            copy[i][j] = points[i][j];
        }
    }
    return copy;
}
void free_copy(int** copy, const int pointsSize) {
    for (int i = 0; i < pointsSize; i++) {
        free(copy[i]);
    }
    free(copy);
}

int maxPoints(const int* const* points, const int pointsSize, const int* pointsColSize) {

    // TODO: unsolved

    int** sortedPoints = create_copy(points, pointsSize, pointsColSize);
    if (sortedPoints == NULL) {
        return -1;
    }

    qsort (sortedPoints, pointsSize, sizeof(int*), compare);

    free_copy(sortedPoints, pointsSize);

    return 0;
}