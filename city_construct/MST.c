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

//Graph ����ü, ��� ����, ������ ����ġ �迭
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

	//������ �ӽ÷� ������ Edge ����ü
	Edge result[MAX_EDGES];
	int e = 0;
	int i = 0;
	int v = 0;
	qsort(graph->edge, graph->edges, sizeof(graph->edge[0]), compareEdges);

	Subset* subsets = (Subset*)malloc(vertices * sizeof(Subset));

	//�� �����鸶�� ����ġ�� ���� ����
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


	//("�ּ� ���� Ʈ���� ����(���� ����ڵ�, ���� �ּ� ó��):\n");
	for (i = 0; i < e; ++i) {

		//printf("���� %c - ���� %c: ����ġ %d��\n", result[i].src + 'A', result[i].dest + 'A', result[i].weight);
		sum += result[i].weight;
	}

	free(subsets);

	return sum;
}