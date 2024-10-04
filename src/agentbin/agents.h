#include <stdio.h>
#include <stdlib.h>

#pragma once

struct Item;
typedef struct item Item;

struct item {
  int id;
  int agent;
};

int* sort(int arr[], int n);
void swap(int *a, int *b);
void heapify(int arr[], int n, int i, int* list);
void printArray(int arr[], int n);
int minAgents(int* items, int N, int capacity, FILE* output);