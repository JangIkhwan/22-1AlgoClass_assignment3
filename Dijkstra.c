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
	// ������ �ε����� 0�������� n-1����

	// i��° ���� ���� �ִ� ��� �󿡼� i��° ��� ������ �ִ� ����� �ε����� �����ϴ� �迭
	int *touch = (int*)malloc(sizeof(int) * n); 
	// i��° ���� ���� �ִ� ����� ���̸� �����ϴ� �迭
	int *length = (int*)malloc(sizeof(int) * n); 

	// ���� ���� 0��° ���� ��
	for (int i = 1; i < n; i++) {
		touch[i] = 0;
		length[i] = W[0][i];
		path_length[i] = length[i];
	}

	//init_edges(F, n);

	for (int k = 0; k < n - 1; k++) { 
		// touch[i]��° ��带 ���������� �������� ��, �ִܰŸ��� ���� �۾����� ����� �ε����� ã��.
		int min = INF;    // length�� ����� �� �� �ּڰ� 
		int near_v;       // length�� ����� �� �� �ּڰ��� ������ ����� �ε���

		//print_array(length, n);

		for (int i = 1; i < n; i++) {
			if (0 <= length[i] && length[i] < min) {
				min = length[i];
				near_v = i;
			}
		}
	
		//printf("near_v : %d, touch[near_v] : %d\n", near_v, touch[near_v]);

		// touch[near_v]��° ���� near_v��° ��带 �մ� ������ �����ؼ� �̸� ���� ���տ� ����
		//edge e = create_edge(touch[near_v], near_v); 
		//insert_edge(F, e); 
		path_length[near_v] = path_length[touch[near_v]] + W[touch[near_v]][near_v];
		
		// ��� ������ ������ ���ؼ�, near_v��° ��带 ���������� ���ļ� ���� ���� �ִ� ��������� Ȯ���ϰ� ������.
		for (int i = 1; i < n; i++) {
			if (length[near_v] + W[near_v][i] < length[i]) {
				length[i] = length[near_v] + W[near_v][i];
				touch[i] = near_v;
				path_length[i] = length[i];
			}
		}
		length[near_v] = -1; // near_v�� ���� �ִ� ��� �� �����ϰ� ��
	}

	free(touch);
	free(length);
}

