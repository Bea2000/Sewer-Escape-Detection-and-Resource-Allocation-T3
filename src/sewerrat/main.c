#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "graph.h"


bool check_arguments(int argc, char **argv)
{
  if (argc != 3)
  {
    printf("Modo de uso: %s INPUT OUTPUT\n", argv[0]);
    printf("Donde:\n");
    printf("\tINPUT es la ruta del archivo de input\n");
    printf("\tOUTPUT es la ruta del archivo de output\n");
    exit(1);
  }

  return true;
}

int main(int argc, char **argv){
    check_arguments(argc, argv);
    FILE *input_file = fopen(argv[1], "r");
    FILE *output_file = fopen(argv[2], "w");
    int n;
    int x;
    int y;
    fscanf(input_file,"%d",&n);
    Graph *graphs = calloc(n,sizeof(Graph));
    int selected[n];
    memset(selected, 0, sizeof(selected));
    for (int i=0; i<n; i++){
      fscanf(input_file, "%d", &x);
      fscanf(input_file, "%d", &y);
      Graph graph;
      graph.x = x;
      graph.y = y;
      graphs[i] = graph;
    }
    path(graphs, n, selected, output_file);
    free(graphs);
    fclose(input_file);
    fclose(output_file);
    return 0;
}

