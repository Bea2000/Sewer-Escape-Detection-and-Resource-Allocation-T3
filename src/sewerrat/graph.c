#include "graph.h"
#include <stdbool.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

int manhattan_distance(Graph graph1, Graph graph2){
    // d(a, b) = |(a1 − b1)| + |(a2 − b2)|
    int dist = graph1.x - graph2.x;
    int dist2 = graph1.y - graph2.y;
    if (dist < 0){\
        dist = dist*-1;
    }
    if (dist2 < 0){\
        dist2 = dist2*-1;
    }
    return dist+dist2;
}

int minDistance(int dist[], bool sptSet[],int n){
  int min = 9999;
  int min_index;
  for(int v=0; v<n;v++){
    if(sptSet[v] == false && dist[v] <= min){
      min = dist[v];
      min_index = v;
    }
  }
  return min_index;
}

void path(Graph* graphs, int n, int selected[n], FILE* output){
  Graph* from = calloc(n-1,sizeof(Graph));
  Graph* to = calloc(n-1,sizeof(Graph));
  int actual = 0;
  selected[0] = 1;

  int x;
  int y;
  int cost = 0;
  int distance;
  int actual_cost;
  int used[n];
  int set_used;
  memset(used, 0, sizeof(used));

  while (actual < n - 1) {
    int min = 9999;
    x = 0;
    y = 0;
    for (int i = 0; i < n; i++) {
      if (selected[i] == 1) {
          for (int j = 0; j < n; j++) {
          distance = manhattan_distance(graphs[i],graphs[j]);
          if (selected[j] == 0) {
              if (min > distance) {
                min = distance;
                actual_cost = distance;
                x = i;
                y = j;
                set_used = used[j] + 1;
              } else if(min == distance && set_used > used[j]){
                min = distance;
                actual_cost = distance;
                x = i;
                y = j;
                set_used = used[j] + 1;
              }
          }
          }
      }
    }
    used[x] = used[x] + 1;
    used[y] = used[y] + 1;
    cost = cost + actual_cost;
    from[actual] = graphs[x];
    to[actual] = graphs[y];
    selected[y] = 1;
    actual++;
  }
  fprintf(output,"%d\n",cost);
  for(int i=0;i<n-1;i++){
    fprintf(output,"%d %d %d %d\n",from[i].x,from[i].y,to[i].x, to[i].y);
  }
  free(from);
  free(to);

}