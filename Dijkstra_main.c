#include <stdio.h>
#include "Dijkstra.h"

// 3가지 테스트 케이스

#define CASE1_SIZE 5 // 각 케이스에서 정점의 개수
#define CASE2_SIZE 5
#define CASE3_SIZE 7

int test_case1[5][5] = {  
	{0, 7, 4, 6, 1},
	{INF, 0, INF, INF, INF},
	{INF, 2, 0, 5, INF},
	{INF, 3, INF, 0, INF},
	{INF, INF, INF, 1, 0}
};

int test_case2[5][5] = { 
	{0, 1, INF, 1, 5},
	{9, 0, 3, 2, INF},
	{INF, INF, 0, 4, INF},
	{INF, INF, 2, 0, 3},
	{3, INF, INF, INF, 0}
};

int test_case3[7][7] = { 
	{0, 7, INF, INF, 3, 10, INF},
	{7, 0, 4, 10, 2, 6, INF},
	{INF, 4, 0, 2, INF, INF, INF},
	{INF, 10, 2, 0, 11, 9, 4},
	{3, 2, INF, 11, 0, INF, 5},
	{10, 6, INF, 9, INF, 0, INF},
	{INF, INF, INF, 4, 5, INF, 0}
};

// Dijkstra 알고리즘을 테스트하는 함수
void test_dijkstra(int n, int W[][VERTEX_MAX]) {
	int path_length[VERTEX_MAX]; // 각 노드로 가는 최단 경로의 길이를 저장하는 배열

	edge_set** F = create_edge_set(VERTEX_MAX); // 최단 경로에 있는 엣지들을 저장하는 엣지 집합

	for (int i = 0; i < n; i++) {
		path_length[i] = 0;
	}

	dijkstra(n, W, F, path_length); // Dijkstra 호출

	// 결과로 얻은 최단 경로와 엣지 집합을 출력
	printf("In path_length[],\n");
	for (int i = 0; i < n; i++) {
		printf("shortest path to the v%d : %d\n", i, path_length[i]);
	}

	printf("\nIn edge set F,\n");
	print_edge_set(F);

	delete_edge_set(F);
}

int main(void) {
	int W[VERTEX_MAX][VERTEX_MAX]; // Dijkstra의 입력으로 쓰일 인접행렬 


	// 인접행렬에 테스트 케이스를 복사
	for (int i = 0; i < CASE1_SIZE; i++) {
		for (int j = 0; j < CASE1_SIZE; j++) {
			W[i][j] = test_case1[i][j];
		}
	}

	printf("test case1\n");
	test_dijkstra(CASE1_SIZE, W); // 테스트 함수 호출

	// 인접행렬에 테스트 케이스를 복사
	for (int i = 0; i < CASE2_SIZE; i++) {
		for (int j = 0; j < CASE2_SIZE; j++) {
			W[i][j] = test_case2[i][j];
		}
	}

	printf("\ntest case2\n");
	test_dijkstra(CASE2_SIZE, W); // 테스트 함수 호출

	// 인접행렬에 테스트 케이스를 복사
	for (int i = 0; i < CASE3_SIZE; i++) {
		for (int j = 0; j < CASE3_SIZE; j++) {
			W[i][j] = test_case3[i][j];
		}
	}
	printf("\ntest case3\n");
	test_dijkstra(CASE3_SIZE, W); // 테스트 함수 호출
}
