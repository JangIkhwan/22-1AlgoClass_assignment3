#include <stdio.h>
#include "Dijkstra.h"

// 3 test cases for Dijkstra
// 3가지 테스트 케이스
#define CASE1_SIZE 5
#define CASE2_SIZE 5
#define CASE3_SIZE 7


int test_case1[5][5] = {  // case from section 4.2
	{0, 7, 4, 6, 1},
	{INF, 0, INF, INF, INF},
	{INF, 2, 0, 5, INF},
	{INF, 3, INF, 0, INF},
	{INF, INF, INF, 1, 0} 
};

int test_case2[5][5] = { // case from section 3.2
	{0, 1, INF, 1, 5},
	{9, 0, 3, 2, INF},
	{INF, INF, 0, 4, INF},
	{INF, INF, 2, 0, 3},
	{3, INF, INF, INF, 0}
};

int test_case3[7][7] = { // case from Chun Inkook's data structure textbook
	{0, 7, INF, INF, 3, 10, INF},
	{7, 0, 4, 10, 2, 6, INF},
	{INF, 4, 0, 2, INF, INF, INF},
	{INF, 10, 2, 0, 11, 9, 4},
	{3, 2, INF, 11, 0, INF, 5},
	{10, 6, INF, 9, INF, 0, INF},
	{INF, INF, INF, 4, 5, INF, 0}
};

// funciton which tests Dijkstra algorithm
void test_dijkstra(int n, int W[][VERTEX_MAX]) {
	int path_length[VERTEX_MAX]; // length of the shortest path from source to i-th vertex

	edge_set** F = create_edge_set(VERTEX_MAX); // set which contains the edges in the shortest paths

	for (int i = 0; i < n; i++) {
		path_length[i] = 0;
	}

	dijkstra(n, W, F, path_length);

	printf("In path_length[],\n");
	for (int i = 0; i < n; i++) {
		printf("shortest path to the v%d : %d\n", i, path_length[i]);
	}

	printf("\nIn edge set F,\n");
	print_edge_set(F);

	delete_edge_set(F);
}

int main(void) {
	int W[VERTEX_MAX][VERTEX_MAX]; // adjacent array. input data for Dijkstra 

	
	// copy test case to input data
	for (int i = 0; i < CASE1_SIZE; i++) {
		for (int j = 0; j < CASE1_SIZE; j++) {
			W[i][j] = test_case1[i][j];
		}
	}

	printf("test case1\n");
	test_dijkstra(CASE1_SIZE, W); // call testing function
	printf("\n");

	for (int i = 0; i < CASE2_SIZE; i++) {
		for (int j = 0; j < CASE2_SIZE; j++) {
			W[i][j] = test_case2[i][j];
		}
	}

	printf("test case2\n");
	test_dijkstra(CASE2_SIZE, W);
	printf("\n");

	for (int i = 0; i < CASE3_SIZE; i++) {
		for (int j = 0; j < CASE3_SIZE; j++) {
			W[i][j] = test_case3[i][j];
		}
	}
	printf("test case3\n");
	test_dijkstra(CASE3_SIZE, W);
}

