#include <stdio.h>
#include <stdlib.h>
#include "Dijkstra.h"

edge* create_edge(int start_v, int end_v, int weight) {
	edge* new_e = (edge*)malloc(sizeof(edge));
	new_e->start_v = start_v;
	new_e->end_v = end_v;
	new_e->weight = weight;

	return new_e;
}

void delete_edge(edge* e) {
	free(e);
}

edge_set* create_edge_set(int size) {
	edge_set* new_set = (edge_set*)malloc(sizeof(edge_set));
	new_set->data = (edge**)malloc(sizeof(edge*) * size);
	new_set->size = size;
	new_set->insert_loc = 0;

	return new_set;
}

void init_edge_set(edge_set* set) {
	for (int i = 0; i < set->size; i++) {
		set->data[i] = NULL;
	}
}

void print_edge_set(edge_set* set) {
	for (int i = 0; i < set->insert_loc; i++) {
		edge* e = set->data[i];
		printf("weight of edge (v%d, v%d) : %d ", e->start_v, e->end_v, e->weight);
	}
}

void insert_to_edge_set(edge_set* set, edge* edge) {
	if (set->insert_loc >= set->size) {
		return;
	}
	set->data[set->insert_loc++] = edge;
}

void delete_edge_set(edge_set* set) {
	for (int i = set->insert_loc; i >= 0; i--) {
		delete_edge(set->data[i]);
	}
	free(set->data);
	free(set);
}

void print_array(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}


void dijkstra(int n, int W[][VERTEX_MAX], int path_length[]) {
	// 정점의 인덱스는 0에서부터 n-1까지

	// i번째 노드로 가는 최단 경로 상에서 i번째 노드 이전에 있는 노드의 인덱스를 저장하는 배열
	int *touch = (int*)malloc(sizeof(int) * n); 
	// i번째 노드로 가는 최단 경로의 길이를 저장하는 배열
	int *length = (int*)malloc(sizeof(int) * n); 

	// 시작 노드는 0번째 노드로 함
	for (int i = 1; i < n; i++) {
		touch[i] = 0;
		length[i] = W[0][i];
		path_length[i] = length[i];
	}

	//init_edges(F, n);

	for (int k = 0; k < n - 1; k++) { 
		// touch[i]번째 노드를 마지막으로 경유했을 때, 최단거리가 가장 작아지는 노드의 인덱스를 찾음.
		int min = INF;    // length에 저장된 값 중 최솟값 
		int near_v;       // length에 저장된 값 중 최솟값을 가지는 노드의 인덱스

		//print_array(length, n);

		for (int i = 1; i < n; i++) {
			if (0 <= length[i] && length[i] < min) {
				min = length[i];
				near_v = i;
			}
		}
	
		//printf("near_v : %d, touch[near_v] : %d\n", near_v, touch[near_v]);

		// touch[near_v]번째 노드와 near_v번째 노드를 잇는 엣지를 생성해서 이를 엣지 집합에 넣음
		//edge e = create_edge(touch[near_v], near_v); 
		//insert_edge(F, e); 
		path_length[near_v] = path_length[touch[near_v]] + W[touch[near_v]][near_v];
		
		// 모든 목적지 정점에 대해서, near_v번째 노드를 마지막으로 거쳐서 가는 것이 최단 경로인지를 확인하고 갱신함.
		for (int i = 1; i < n; i++) {
			if (length[near_v] + W[near_v][i] < length[i]) {
				length[i] = length[near_v] + W[near_v][i];
				touch[i] = near_v;
				path_length[i] = length[i];
			}
		}
		length[near_v] = -1; // near_v는 이제 최단 경로 상에 존재하게 됨
	}

	free(touch);
	free(length);
}

