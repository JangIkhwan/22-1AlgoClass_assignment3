#pragma once
#define INF 1000000
#define VERTEX_MAX 50

// 엣지 구조체
struct edge {
	int start_v; // 엣지의 시작점
	int end_v;   // 엣지의 끝점
	int weight;  // 엣지의 가중치
};
typedef struct edge edge;

// 엣지 집합 구조체
struct edge_set {
	edge** data; // 엣지들을 가리키는 포인터 배열
	int size;    // 최대로 저장할 수 있는 엣지의 수
	int insert_loc; // 배열에서 새로운 엣지가 삽입될 위치
};

typedef struct edge_set edge_set;

edge* create_edge(int start_v, int end_v, int weight);
void delete_edge(edge* e);

edge_set* create_edge_set(int size);
void init_edge_set(edge_set* set);
void print_edge_set(edge_set* set);
void insert_to_edge_set(edge_set* set, edge* edge);
void delete_edge_set(edge_set* set);

void dijkstra(int n, int **W, int path_length[]);