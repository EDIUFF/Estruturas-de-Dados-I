//
// Created by Mateus Rodrigues on 04/10/2015.
//
#include "../headers/the_lazy_runner.h"

int *shortestPath(Graph *g, int start, int end) {
    HashMap *distances = newHashMap();
    HashMap *past = newHashMap();
    ArrayList *vertices = verticesG(g);
    int i, n;
    for (i = 0, n = sizeAL(vertices); i < n; ++i) {
        int *x = (int) malloc(sizeof(int));
        *x = -1;
        putHM(distances, getAL(vertices, i), x);
        putHM(past, getAL(vertices, i), NULL);
    }
    destroyAL(vertices);
    int *s = (int) malloc(sizeof(int));
    *s = start;
    putHM(distances, s, 0);
    Deque *nextVertices = newDeque();
    HashSet *pastVertices = newHashSet();
    pushD(nextVertices, s);
    while (sizeD(nextVertices) > 0) {
        int *actualVertex = popD(nextVertex);
        ArrayList *edges = edges_ofG(g, nextVertex);
        for (i = 0, n = sizeAL(vertices); i < n; ++i) {
            Edge *actualEdge = getAL(edges, i);
            int *actualDistance = getHM(distances, toE(actualEdge));
            int newDistance = getHM(distances, actualVertex) + weightE(actualEdge);
            if (actualDistance > newDistance) {
                putHM(distances, toE(actualEdge), newDistance);
                putHM(past, toE(actualEdge), actualVertex);
            }
            if (containsHS(pastVertices, toE(actualEdge)) == 0) {
                pushD(nextVertices, toE(actualEdge));
                addHS(pastVertices, toE(actualEdge));
            }
        }
    }
    destroyD(nextVertices);
    destroyHM(distances);
    int *reversePath = (int *) malloc(sizeof(int) * (1 + sizeHS(pastVertices)));
    reversePath[0] = sizeHS(pastVertices);
    int pastVertex = end;
    i = 0;
    do {
        reversePath[i++] = pastVertex;
        pastVertex = getHM(past, pastVertex);
    } while (pastVertex != start);
    int *path = (int *) malloc(sizeof(int) * (1 + i));
    path[0] = i;
    int j;
    for (j = i; j >= 0; --j) {
        path[j + 1] = reversePath[i - j + 1];
    }
    free(reversePath);
    destroyHM(past);
    return path;
}

int *theLazyRunner(Graph *g, int start, int *targets, int nTargets) {
    int *path = shortestPath(g, start, targets[0]);
    int i;
    for (i = 0; i < nTargets - 1; ++i) {
        int *subPath = shortestPath(g, targets[i], targets[i + 1]);
        path = (int *) realloc(path, sizeof(int) * (1 + path[0] + subPath[0]));
        int j;
        for (j = 0; j < subPath[0]; ++j)
            path[path[0] + 1] = subPath[j + 1];
        path[0] += subPath[0];
        free(subPath);
    }
    return path;
}

