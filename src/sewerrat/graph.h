#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#pragma once

struct Graph;
typedef struct graph Graph;

struct graph {
  int x;
  int y;
};

int manhattan_distance(Graph graph1, Graph graph2);

void path(Graph* graphs, int n, int selected[n], FILE* output);

int minDistance(int dist[], bool sptSet[],int n);