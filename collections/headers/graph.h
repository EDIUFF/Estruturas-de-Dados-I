/* 
 * File:   graph.h
 * Author: gems
 *
 * Created on September 20, 2015, 5:59 PM
 */

#ifndef GRAPH_H
#define	GRAPH_H

#include <stdio.h>
#include "hash_map.h"
#include "hash_set.h"

typedef struct Vertex {
    void * ID;
    void* weight;
} Vertex;

typedef struct Edge {
    Vertex* source;
    Vertex* target;
    void* weight;
} Edge;

typedef struct Graph {
    HashMap * graph;
    int(*cmpV)(const void*, const void*);
    int(*cmpVW)(const void*, const void*);
    int(*cmpEW)(const void*, const void*);
} Graph;

Graph* newGraph(int(*cmpV)(const void*, const void*), int(*cmpVW)(const void*, const void*), int(*cmpEW)(const void*, const void*));
void putG(Graph* g, void* ID, void* weight);
void removeG(Graph* g, void* ID);
void connectG(Graph* g, void* sourceID, void* targetID, void* weight);
void disconnectG(Graph* g, void* sourceID, void* targetID);
void connectG(Graph* g, void* sourceID, void* targetID, void*(*changeWeight)(const void*));
Iterator* verticesG(Graph* g);
Iterator* edgesG(Graph* g);

#endif	/* GRAPH_H */

