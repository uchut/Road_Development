#include <stdio.h>
#include <stdlib.h>
#include "MST.h"

int compareEdges(const void* a, const void* b) {
	Edge* edgeA = (Edge*)a;
	Edge* edgeB = (Edge*)b;
	return edgeA->weight - edgeB->weight;
}

int find(Subset subsets[], int i) {
	if (subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);
	return subsets[i].parent;
}

void unionSets(Subset subsets[], int x, int y) {
	int rootX = find(subsets, x);
	int rootY = find(subsets, y);

	if (subsets[rootX].rank < subsets[rootY].rank) {
		subsets[rootX].parent = rootY;
	}
	else if (subsets[rootX].rank > subsets[rootY].rank) {
		subsets[rootY].parent = rootX;
	}
	else {
		subsets[rootY].parent = rootX;
		subsets[rootX].rank++;
	}
}

//Graph 구조체, 노드 개수, 간선의 가중치 배열
void initGraph(Graph* g, int v, int* n)
{
	g->vertices = v;
	g->edges = 0;
	int count = 0;
	int maxedges = 0;
	for (int i = 0; i < v; ++i)
	{
		for (int j = i + 1; j < v; ++j)
		{
			if (n[count] != -1)
			{
				g->edge[g->edges].src = i;
				g->edge[g->edges].dest = j;
				g->edge[g->edges].weight = n[count];
				g->edges++;
			}
			count++;
		}
	}
}

int kruskalMST(Graph* graph) {
	int vertices = graph->vertices;

	//정답을 임시로 저장할 Edge 구조체
	Edge result[MAX_EDGES];
	int e = 0;
	int i = 0;
	int v = 0;
	qsort(graph->edge, graph->edges, sizeof(graph->edge[0]), compareEdges);

	Subset* subsets = (Subset*)malloc(vertices * sizeof(Subset));

	//각 간선들마다 가중치에 의한 선별
	for (v = 0; v < vertices; ++v) {
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	while (e < vertices - 1 && i < graph->edges) {
		Edge nextEdge = graph->edge[i++];

		int x = find(subsets, nextEdge.src);
		int y = find(subsets, nextEdge.dest);

		if (x != y) {
			result[e++] = nextEdge;
			unionSets(subsets, x, y);
		}
	}
	int sum = 0;


	//("최소 신장 트리의 간선(정답 출력코드, 이후 주석 처리):\n");
	for (i = 0; i < e; ++i) {

		//printf("마을 %c - 마을 %c: 가중치 %d억\n", result[i].src + 'A', result[i].dest + 'A', result[i].weight);
		sum += result[i].weight;
	}

	free(subsets);

	return sum;
}