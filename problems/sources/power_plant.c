//
// Created by Mateus Rodrigues on 04/10/2015.
//

#include "../headers/power_plant.h"

Graph* powerPlant(Graph* g){
    ArrayList* vertices = verticesG(g);
    Graph* tree = newGraph(cmpG(g));
    int size = sizeAL(vertices);
    int i;
    for (i = 0; i < size; i++)
        putVertexG(tree, getAL(vertices));
    ArrayList* edges = edgesG(g);
    size = sizeAL(edges);
    sortAL(edges);
    for (i = 0; i < size; i++) {
        Edge* e = getAL(edges, i);
        connectG(tree, fromE(e), toE(e), weightE(e));
        if (hasCicleG(tree))
            disconnect(tree, fromE(e), toE(e), weightE(e));
    }
    return tree;
}

