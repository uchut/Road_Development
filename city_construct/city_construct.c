#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include "MST.h"

#define LINESIZE 50
#define MAX_VERTICES 100
#define INF 100000000	//������ �ǹ�
#define NONE_ -1	//�������� ������ �ǹ�

//�ʱ� ���
int heart = 3;
int max_stage = 0;

//MST�˰��򿡼� ���� ���� ����, (�����ϴ�)������ ����, (�������� �ʴ� ���� ����)������ ����, ������ ����ġ �迭
typedef struct {
	int node;
	int lineSize;
	int fullLine;
	int line[LINESIZE];
} MST;

//���� �Լ� �����, �Լ��� ��Ŀ������ �Ʒ� �����ο��� Ȯ��
void storyPrint(const char* text);
void intro(void);
int randomMap(void);
void lineWeight(MST* mst);
void randomline(MST* mst);

void printMapMST(int randNum);
void selectMST(MST* mst, int budget);
int numEquals(int num[], int budget, int num2[], MST* mst);

int main(void) {
	intro();	//��Ʈ�� ���丮 ��� �Լ�
	printf("\n���� �Ǽ��� �����ϼ̽��ϴ�...\n����� �ְ� �޼� ��������: %d", max_stage);
	return 0;
}

//��Ʈ�� ���丮
void intro(void) {
	printf("��");
	Sleep(30);
	printf("��");
	Sleep(30);
	printf("��");
	printf("��");
	printf(" 2"); Sleep(30); printf("0"); Sleep(30); printf("2"); Sleep(30); printf("4"); Sleep(30); printf("��");
	Sleep(2000);
	printf("\n");

	const char* text1 = "���ѹα��� ���� ��������� ����� ���� �Ǿ���";
	const char* text2 = "�̿� ���� ���δ� ���ο� �ŵ��� ��ȹ�� �����ϴµ�...";
	const char* text3 = "����� ������ ���ð��� �����";
	const char* text4 = "���õ� �簳�� ��ǳ�� ������ �ŵ��� ���ڿ� ���� ���ο� ������ �����Ϸ��� �Ѵ�.";
	const char* text5 = "���ô� ���� �׸��� ���� ������ ������ �����̴�.";

	const char* text8 = "����� ���ο� ���÷� �߷ɹ޾Ƽ� ���ο� ������ ���� �Ǽ��� ����ϰ� �Ǿ����ϴ�.";
	//���丮 ���
	for (int i = 0; text1[i] != '\0'; i++) {
		putchar(text1[i]); 
		Sleep(30); 
	}
	Sleep(200);
	printf("."); Sleep(200); printf("."); Sleep(200); printf(". \n");
	Sleep(3000);

	system("cls");

	for (int i = 0; text2[i] != '\0'; i++) {
		putchar(text2[i]);
		Sleep(30); 
	}
	Sleep(3000);
	printf("\n\n");
	system("cls");
	Sleep(1500);

	for (int i = 0; text3[i] != '\0'; i++) {
		putchar(text3[i]); 
		Sleep(30);
	}
	Sleep(3000);
	printf("\n");
	system("cls");


	for (int i = 0; text4[i] != '\0'; i++) {
		putchar(text4[i]);  
		Sleep(30); 
	}
	Sleep(3000);
	printf("\n");
	for (int i = 0; text5[i] != '\0'; i++) {
		putchar(text5[i]); 
		Sleep(30); 
	}
	Sleep(2000);
	printf("\n");

	// ���� ����
	while (1) {
		int temp = randomMap();

		printMapMST(temp);
		Sleep(1000);
		max_stage++;
		if (heart == 0) break;
		system("cls");
		printf("\n");
		for (int i = 0; text8[i] != '\0'; i++) {
			putchar(text8[i]);
			Sleep(30); 
		}
		Sleep(200);
		printf("."); Sleep(200); printf("."); Sleep(200); printf(".");
		Sleep(3000);
		printf("\n");
		system("cls");
	}
}

void storyPrint(const char* text) {
	for (int i = 0; text[i] != '\0'; i++) {
		putchar(text[i]);  
		Sleep(30); 
	}
}

//� ���� ����� �� �����ϴ� �Լ� (�� �߰��Ǹ� ���� ���� �ٲٱ�)
int randomMap(void) {
	srand(time(NULL));
	int randomNum = rand() % 3 + 1;
	return randomNum;
}

MST* globalMST = NULL;

void printMapMST(int randNum) {
	if (globalMST != NULL) {
		free(globalMST);
		globalMST = NULL;
	}

	// ���ο� MST �Ҵ�
	globalMST = (MST*)malloc(sizeof(MST));
	if (globalMST == NULL) {
		printf("Memory allocation failed!\n");
		exit(1);
	}
	int current_stage = max_stage + 1;
	printf("���� ��������: %d", current_stage);
	const char* type0 = "�� ���θ� ���� ��� ������ ���θ� ���µ� ���� �ݾ��� ������ ����.";

	if (randNum == 1) {
		globalMST->node = 9;	globalMST->lineSize = 11; globalMST->fullLine = 36;
		//�� 1 MST ���� ����(0�� �����ϸ� �ʱ�ȭ�� ����, -1�� �������� ����)
		globalMST->line[0] = 0;	globalMST->line[1] = 0; globalMST->line[2] = 0;	globalMST->line[3] = -1;	globalMST->line[4] = -1; globalMST->line[5] = -1; globalMST->line[6] = -1; globalMST->line[7] = -1;
		globalMST->line[8] = -1; globalMST->line[9] = -1; globalMST->line[10] = -1; globalMST->line[11] = -1; globalMST->line[12] = 0; globalMST->line[13] = -1; globalMST->line[14] = -1;
		globalMST->line[15] = -1; globalMST->line[16] = 0; globalMST->line[17] = -1;  globalMST->line[18] = -1; globalMST->line[19] = -1;  globalMST->line[20] = -1;
		globalMST->line[21] = 0; globalMST->line[22] = -1; globalMST->line[23] = 0;  globalMST->line[24] = 0;  globalMST->line[25] = -1;
		globalMST->line[26] = 0; globalMST->line[27] = -1; globalMST->line[28] = -1;  globalMST->line[29] = 0;
		globalMST->line[30] = -1; globalMST->line[31] = -1; globalMST->line[32] = 0;
		globalMST->line[33] = -1; globalMST->line[34] = -1;
		globalMST->line[35] = -1;
		int budget = 0;
		printf("\n\n=================================================================================\n\n");
		printf("\t\t  ** A ***");
		printf("\n\t       ***   *    ****\n\t    ***\t     *        ****\n");
		printf("\tB **         *            *** C\n");
		printf("\t*	     *                *\n");
		printf("\t*            *               *\n");
		printf("\t*            *    \t    *\n");
		printf("\t*      ***** D ************ E ******** F");
		printf("\n\tG *****       *              *        *\n\t\t       *              *     *\n");
		printf("\t\t\tH\t       *  *\n");
		printf("\t\t\t\t\tI");
		printf("\n\n=================================================================================\n\n");
		for (int i = 0; type0[i] != '\0'; i++) {
			putchar(type0[i]); 
			Sleep(30);  
		}
		printf("\n");

		randomline(globalMST);
		lineWeight(globalMST);
		budget = findMST(globalMST);
		printf("���� : %d���\n", budget);
		selectMST(globalMST, budget);
		Sleep(800);
	}
	if (randNum == 2) {
		globalMST->node = 10; globalMST->lineSize = 12; globalMST->fullLine = 45;
		//�� 2 MST ���� ����
		globalMST->line[0] = 0; globalMST->line[1] = 0; globalMST->line[2] = -1; globalMST->line[3] = -1; globalMST->line[4] = -1; globalMST->line[5] = -1; globalMST->line[6] = -1; globalMST->line[7] = -1; globalMST->line[8] = -1;
		globalMST->line[9] = -1; globalMST->line[10] = 0; globalMST->line[11] = -1; globalMST->line[12] = -1; globalMST->line[13] = -1; globalMST->line[14] = -1; globalMST->line[15] = -1; globalMST->line[16] = -1;
		globalMST->line[17] = 0; globalMST->line[18] = -1; globalMST->line[19] = 0; globalMST->line[20] = -1; globalMST->line[21] = -1; globalMST->line[22] = -1; globalMST->line[23] = -1;
		globalMST->line[24] = 0; globalMST->line[25] = -1; globalMST->line[26] = 0; globalMST->line[27] = -1; globalMST->line[28] = -1; globalMST->line[29] = -1;
		globalMST->line[30] = -1; globalMST->line[31] = -1; globalMST->line[32] = -1; globalMST->line[33] = -1; globalMST->line[34] = -1;
		globalMST->line[35] = 0; globalMST->line[36] = -1; globalMST->line[37] = -1; globalMST->line[38] = -1;
		globalMST->line[39] = 0; globalMST->line[40] = 0; globalMST->line[41] = -1;
		globalMST->line[42] = -1; globalMST->line[43] = 0;
		globalMST->line[44] = 0;
		int budget = 0;
		printf("\n\n=================================================================================\n\n");
		printf("\t\t    A ***** B\n");
		printf("\t\t   *         *\n");
		printf("\t\t  *          *\n");
		printf("\t\t *            *      ***** E\n");
		printf("\t\tC *********** D *****\n");
		printf("\t\t *            *\n");
		printf("\t\t *            *\n");
		printf("\t\t  F ****      *\n");
		printf("\t\t        ***** G ********* H\n");
		printf("\t\t               *           *\n");
		printf("\t\t                *           *\n");
		printf("\t\t                 *           *\n");
		printf("\t\t                  *           *\n");
		printf("\t\t                   *        ** J\n");
		printf("\t\t                    *    ***\n");
		printf("\t\t                     I **\n");
		printf("\n\n=================================================================================\n\n");
		for (int i = 0; type0[i] != '\0'; i++) {
			putchar(type0[i]); 
			Sleep(30); 
		}
		printf("\n");

		randomline(globalMST);
		lineWeight(globalMST);
		budget = findMST(globalMST);
		printf("���� : %d���\n", budget);
		selectMST(globalMST, budget);
		Sleep(800);
	}
	if (randNum == 3) {
		//�� 3 MST ���� ����
		globalMST->node = 11; globalMST->lineSize = 20; globalMST->fullLine = 55;
		globalMST->line[0] = 0; globalMST->line[1] = 0; globalMST->line[2] = -1; globalMST->line[3] = -1; globalMST->line[4] = -1; globalMST->line[5] = -1; globalMST->line[6] = -1; globalMST->line[7] = -1; globalMST->line[8] = -1; globalMST->line[9] = -1;
		globalMST->line[10] = 0; globalMST->line[11] = 0; globalMST->line[12] = -1; globalMST->line[13] = -1; globalMST->line[14] = -1; globalMST->line[15] = -1; globalMST->line[16] = -1; globalMST->line[17] = -1; globalMST->line[18] = -1;
		globalMST->line[19] = 0; globalMST->line[20] = 0; globalMST->line[21] = 0; globalMST->line[22] = -1; globalMST->line[23] = -1; globalMST->line[24] = -1; globalMST->line[25] = -1; globalMST->line[26] = -1;
		globalMST->line[27] = 0; globalMST->line[28] = -1; globalMST->line[29] = 0; globalMST->line[30] = -1; globalMST->line[31] = -1; globalMST->line[32] = -1; globalMST->line[33] = 0;
		globalMST->line[34] = 0; globalMST->line[35] = -1; globalMST->line[36] = -1; globalMST->line[37] = -1; globalMST->line[38] = 0; globalMST->line[39] = 0;
		globalMST->line[40] = -1; globalMST->line[41] = 0; globalMST->line[42] = -1; globalMST->line[43] = 0; globalMST->line[44] = -1;
		globalMST->line[45] = -1; globalMST->line[46] = 0; globalMST->line[47] = -1; globalMST->line[48] = 0;
		globalMST->line[49] = -1; globalMST->line[50] = 0; globalMST->line[51] = -1;
		globalMST->line[52] = -1; globalMST->line[53] = 0;
		globalMST->line[54] = 0;

		int budget = 0;
		printf("\n\n=================================================================================\n\n");
		printf("\t\t          A    \n");
		printf("\t\t        *  *       \n");
		printf("\t\t      *     *        \n");
		printf("\t\t    B ***** C *\n");
		printf("\t\t    *     * *   *\n");
		printf("\t\t    *   *   *     *\n");
		printf("\t\t    * *     *       *\n");
		printf("\t\t    D ***** E ******* F\n");
		printf("\t\t   * *     * *       * *\n");
		printf("\t\t  *    * *    *     *   *\n");
		printf("\t\t G **** K      *   *     H\n");
		printf("\t\t  *  **   ***   * *   ***\n");
		printf("\t           I         *** J ***\n");
		printf("\n\n=================================================================================\n\n");
		for (int i = 0; type0[i] != '\0'; i++) {
			putchar(type0[i]); 
			Sleep(30);  
		}
		printf("\n");

		randomline(globalMST);
		lineWeight(globalMST);
		budget = findMST(globalMST);
		printf("���� : %d���\n", budget);
		selectMST(globalMST, budget);
		Sleep(800);
	}
	if (globalMST != NULL) {
		free(globalMST);
		globalMST = NULL;
	}
}

//MST�������� ����ġ�� �������� ���� �ϰ� lineWeight()�� ���� �� ������ ���
void randomline(MST* mst) {
	int i = 0;

	//mst����ü�� �ִ� �������� ����ġ(������)���� ����
	srand(time(NULL));
	for (i = 0; i < mst->fullLine; i++) {
		if (mst->line[i] == 0) {

			mst->line[i] = rand() % 10 + 10;

		}
		else if (mst->line[i] == -1) {
			mst->line[i] = -1;
		}
	}
}

//������ ����ġ(����) ���
void lineWeight(MST* mst) {
	int i = 0;
	int j = 0, x = 0;
	for (i = 0; i < mst->node - 1; i++) {
		for (j = i + 1; j < mst->node; j++) {
			if (mst->line[x] != -1) {
				printf("[%2d]�� ���� %c - %c �Ǽ� �� ���� : %d��\n", x, i + 'A', j + 'A', mst->line[x]);
			}
			x++;
		}
	}
}

//�Ǽ��� ���ε��� �ĺ��� ������ ���ε��� ������ �����ϵ��� ��.
void selectMST(MST* mst, int budget) {
	int i = 0;
	int j = 0, x = 0;
	int num[LINESIZE] = { 0 }, num2[LINESIZE] = { 0 };
	int pass_fail = 0;

	printf("\n��� �������� �ٸ� ��� ������ �� �� �ֵ��� ���ѵ� �������� ���θ� �Ǽ��Ͻÿ�.\n");

	for (i = 0; i < mst->node - 1; i++) {
		for (j = i + 1; j < mst->node; j++) {
			if (mst->line[x] != -1) {
				//printf("%c - %c : %d�� ����\n", i + 'A', j + 'A', x);
			}
			x++;
		}
	}

	//�������� �ĺ��� num2[]�� ��� �ڵ�
	j = 0;
	for (i = 0; i < mst->fullLine; i++) {
		if (mst->line[i] != -1) {
			num2[j] = mst->line[i];
		}
	}

re:
	i = 0;
	while (1) {
		printf("�Ǽ��� ������ ��ȣ�� �Է� �� ����(-1 �Է½� ������ ��� ���� ���� Ȯ��) : ");
		scanf_s("%d", &num[i]);
		if (num[i] == -1) {
			break;
		}
		else if (mst->line[num[i]] == -1) {
			printf("�߸��� �Է��Դϴ�.\nó������ �ٽ� �Է����ּ���.\n");
			goto re;
		}
		i++;
	}

	pass_fail = numEquals(num, budget, num2, mst);
	if (pass_fail == -1) {
		heart--;
		printf("< ���� ��� : %d >\n", heart);
	}
}

//�־��� �������� ���θ� �Ǽ� �� �� �ִ����� Ȯ���Ͽ� ���� ���� ���θ� �Ǽ����� ���ϸ� -1��, �Ǽ� �����ϸ� 0�� ����
int numEquals(int num[], int budget, int num2[], MST* mst) {
	int i = 0, sum = 0;
	for (i = 0; i < mst->lineSize && num[i] != -1; i++) {
		if (num[i] == -1) {
			continue;
		}
		sum += mst->line[num[i]];
	}
	printf("%d��� ���, ���� : %d\n", sum, budget);
	if (budget == sum) {
		printf("�־��� �������� �����ϰ� ���θ� �Ǽ��Ͽ����ϴ�.\n");
		return 0;
	}
	else if (budget > sum) {
		printf("��� ������ �մ� ���θ� �Ǽ����� ���Ͽ����ϴ�.\n");
		return -1;
	}
	else {
		printf("������ �ʰ��Ͽ� ���θ� �Ǽ��Ͽ����ϴ�.\n");
		return -1;
	}
}

//�������� ����ġ(����)�� �޾� ���, ���� �ּ� ������ ����
int findMST(MST* mst) {
	int vertices = 0, edges = 0;
	int budget = 0, i = 0;
	Graph* graph = (Graph*)malloc(sizeof(Graph));

	//mst����ü�� ����� �����迭�� graph ����ü�� �ű�
	for (i = 0; i < mst->fullLine; i++) {
		graph->edge[i].weight = mst->line[i];
	}
	graph->vertices = mst->node;	//���� ���� �ű�
	graph->edges = mst->fullLine;	//�������� �ʴ� ���� + �����ϴ� ���� ���� �ű�

	for (int i = 0; i < mst->node - 1; ++i) {
		for (int j = i + 1; j < mst->node; ++j) {
			int weight;
			weight = mst->line[i];
			if (weight != -1) {
				graph->edge[edges].src = i;
				graph->edge[edges].dest = j;
				graph->edge[edges].weight = weight;
				edges++;
			}
		}
	}
	graph->edges = edges;
	initGraph(graph, graph->vertices, mst->line);
	budget = kruskalMST(graph);

	free(graph);
	return budget;
}