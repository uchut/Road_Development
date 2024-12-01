#ifndef MST_H
#define MST_H

#define MAX_EDGES 100

// 간선 구조체
typedef struct {
	int src, dest, weight;
} Edge;

// Graph 구조체(vertices : 노드 개수, edges : 간선 개수)
typedef struct {
	int vertices, edges;
	Edge edge[MAX_EDGES];
} Graph;

// Subset 구조체
typedef struct {
	int parent;
	int rank;
} Subset;

int compareEdges(const void* a, const void* b);

// 부모 노드 찾기
int find(Subset subsets[], int i);

// 두 집합 합치기
void unionSets(Subset subsets[], int x, int y);

// Kruskal MST 알고리즘
int kruskalMST(Graph* graph);
// 그래프 초기화 함수
void initGraph(Graph* g, int v, int* n);


#endif