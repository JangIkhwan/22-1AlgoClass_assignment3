#include <stdio.h>
#include <stdlib.h>
#include "Dijkstra.h"

// ���ͽ�Ʈ�� �˰���
// ���� : ������ ����, �������, ���� ���� ������, �� �������� ���� �ִܰŸ��� �����ϱ� ���� �迭
void dijkstra(int n, int W[][VERTEX_MAX], edge_set* F, int path_length[]) {
	// ������ �ε����� 0�������� n-1����

	// i��° ���� ���� �ִ� ��� �󿡼� i��° ��� ������ �ִ� ����� �ε����� �����ϴ� �迭
	int* touch = (int*)malloc(sizeof(int) * n);
	// i��° ���� ���� �ִ� ����� ���̸� �����ϴ� �迭
	int* length = (int*)malloc(sizeof(int) * n);

	// ���� ���� 0��° ���
	for (int i = 1; i < n; i++) {
		touch[i] = 0;
		length[i] = W[0][i];
	}

	init_edge_set(F);

	for (int k = 0; k < n - 1; k++) {
		int min = INF;    // length�� ����� �� �� �ּڰ��� �����ϴ� ����
		int near_v;       // length�� ����� �� �� �ּڰ��� ������ ����� �ε����� �����ϴ� ����

		// touch[i]��° ��带 ���������� �������� ��, �ִܰŸ��� ���� ����� �ε����� ã��
		for (int i = 1; i < n; i++) {
			if (0 <= length[i] && length[i] < min) {
				min = length[i];
				near_v = i;
			}
		}

		// touch[near_v]��° ���� near_v��° ��带 �մ� ������ �����ؼ� �̸� ���� ���տ� ����
		edge* e = create_edge(touch[near_v], near_v, W[touch[near_v]][near_v]); 
		insert_to_edge_set(F, e); 

		// ��� ������ ������ ���ؼ�, near_v��° ��带 ���������� ���ļ� ���� ���� �� ª������ Ȯ���ϰ� �ִܰŸ��� ����
		for (int i = 1; i < n; i++) {
			if (length[near_v] + W[near_v][i] < length[i]) {
				length[i] = length[near_v] + W[near_v][i];
				touch[i] = near_v;
				path_length[i] = length[i];
			}
		}
		
		path_length[near_v] = length[near_v]; // near_v�� ���� �ִܰŸ��� �迭�� ����
		length[near_v] = -1; // near_v��° ��带 ���� Ž������ ������
	}

	free(touch);
	free(length);
}

// ���ο� ������ �����ؼ� ��ȯ�ϴ� �Լ�
edge* create_edge(int start_v, int end_v, int weight) {
	edge* new_e = (edge*)malloc(sizeof(edge));
	new_e->start_v = start_v;
	new_e->end_v = end_v;
	new_e->weight = weight;

	return new_e;
}

// �������� ������ ������ �����ϴ� �Լ�
void delete_edge(edge* e) {
	free(e);
}

// ������ ������ �������� �����ؼ� ��ȯ�ϴ� �Լ�
edge_set* create_edge_set(int size) {
	edge_set* new_set = (edge_set*)malloc(sizeof(edge_set));
	new_set->data = (edge**)malloc(sizeof(edge*) * size); 
	new_set->size = size;
	new_set->insert_loc = 0;

	return new_set;
}

// ���� ������ �ʱ�ȭ�ϴ� �Լ�
void init_edge_set(edge_set* set) {
	for (int i = 0; i < set->size; i++) {
		set->data[i] = NULL;
	}
}

// ���� ������ ����ϴ� �Լ�
void print_edge_set(edge_set* set) {
	for (int i = 0; i < set->insert_loc; i++) {
		edge* e = set->data[i];
		if (e != NULL) {
			printf("weight of edge (v%d, v%d) : %d \n", e->start_v, e->end_v, e->weight);
		}
	}
}

// ������ ���� ���տ� �߰��ϴ� �Լ�
void insert_to_edge_set(edge_set* set, edge* edge) {
	if (set->insert_loc >= set->size) {
		return;
	}
	set->data[set->insert_loc++] = edge;
}

// ���� ������ �����ϴ� �Լ�
void delete_edge_set(edge_set* set) {
	for (int i = set->insert_loc; i >= 0; i--) {
		delete_edge(set->data[i]);
	}
	free(set->data);
	free(set);
}



