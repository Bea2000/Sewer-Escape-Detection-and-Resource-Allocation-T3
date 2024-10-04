#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agents.h"
#include <stdbool.h>


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

    int capacity;
    fscanf(input_file,"%d",&capacity);
    int n_items;
    fscanf(input_file,"%d",&n_items);
    int* items = calloc(n_items,sizeof(items));
    int item;
    for (int i=0;i<n_items;i++){
      fscanf(input_file,"%d",&item);
      items[i] = item;
    }
    int value = minAgents(items, n_items, capacity, output_file);
    printf("min value is: %d\n", value);
    fclose(input_file);
    fclose(output_file);
    free(items);
    return 0;
}