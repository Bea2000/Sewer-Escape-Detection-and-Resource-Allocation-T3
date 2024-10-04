#include "agents.h"

int minAgents(int* items, int N, int capacity, FILE* output)
{
	int ans = 0;
	int L = 0;
  int R = N - 1;
  int* arr;
	Item* list = calloc(N,sizeof(Item));
	arr = sort(items, N);
	while (L <= R) {
		int qty = 0;
    while((qty+items[R]<=capacity || qty+items[L]<=capacity) && L<=R){
      if(qty+items[R]<=capacity && L<=R){
        qty = qty + items[R];
        Item itemR;
        itemR.agent = ans;
        itemR.id = R;
        list[R] = itemR;
        R--;
      }
      else if(qty + items[L]<=capacity && L<=R){
        qty = qty + items[L];
        Item itemL;
        itemL.agent = ans;
        itemL.id = L;
        list[L] = itemL;
        L++;
      }
    }
    ans ++;
  }
	fprintf(output, "%d\n", ans);
	for (int i=0;i<ans;i++){
		for (int j=0;j<N;j++){
			if(list[j].agent == i){
				fprintf(output, "%d ", list[arr[j]].id);
			}
		}
		fprintf(output, "\n");
	}
	free(list);
  free(arr);
	return ans;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
void heapify(int arr[], int n, int i, int* list) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
      largest = left;
    if (right < n && arr[right] > arr[largest])
      largest = right;
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      int tmp = list[i];
      list[i] = list[largest];
      list[largest] = tmp;
      heapify(arr, n, largest, list);
    }
  }
  
int* sort(int arr[], int n) {
    int* list = calloc(n,sizeof(int));
    for(int i=0; i<n;i++){
      list[i] = i;
    }
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i, list);
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
      int tmp = list[i];
      list[i] = list[0];
      list[0] = tmp;
      heapify(arr, i, 0, list);
    }
    return list;
  }