#ifndef MST_H
#define MST_H

#define MAX_EDGES 100

// ���� ����ü
typedef struct {
	int src, dest, weight;
} Edge;

// Graph ����ü(vertices : ��� ����, edges : ���� ����)
typedef struct {
	int vertices, edges;
	Edge edge[MAX_EDGES];
} Graph;

// Subset ����ü
typedef struct {
	int parent;
	int rank;
} Subset;

int compareEdges(const void* a, const void* b);

// �θ� ��� ã��
int find(Subset subsets[], int i);

// �� ���� ��ġ��
void unionSets(Subset subsets[], int x, int y);

// Kruskal MST �˰���
int kruskalMST(Graph* graph);
// �׷��� �ʱ�ȭ �Լ�
void initGraph(Graph* g, int v, int* n);


#endif