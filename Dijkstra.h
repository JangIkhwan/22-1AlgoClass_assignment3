#pragma once
#define INF 1000000
#define VERTEX_MAX 50

struct edge {
	int start_v; // 엣지의 시작점
	int end_v;   
	int weight;
};
typedef struct edge edge;

struct edge_set {
	edge** data;
	int size;
	int insert_loc;
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