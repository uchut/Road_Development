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

//MST�˰����򿡼� ���� ���� ����, (�����ϴ�)������ ����, (�������� �ʴ� ���� ����)������ ����, ������ ����ġ �迭
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
	//printMapMST(1);
	intro();	//��Ʈ�� ���丮 ��� �Լ�
	printf("\n���� �Ǽ��� �����ϼ̽��ϴ�.");
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
	const char* text3 = "����� ������� ���ð��� �����";
	const char* text4 = "����õ� �簳�� ��ǳ�� ������ �ŵ��� ���ڿ� ���� ���ο� ������ �����Ϸ��� �Ѵ�.";
	const char* text5 = "����ô� ���� �׸��� ���� ������ ������ �����̴�.";

	const char* text8 = "����� ���ο� ���÷� �߷ɹ޾Ƽ� ���ο� ������ ���� �Ǽ��� ����ϰ� �Ǿ����ϴ�.";
	//���丮 ���
	for (int i = 0; text1[i] != '\0'; i++) {
		putchar(text1[i]);  // �� ���ھ� ���
		Sleep(30);  // 30 �и��� ���
	}
	Sleep(200);
	printf("."); Sleep(200); printf("."); Sleep(200); printf(". \n");
	Sleep(3000);

	system("cls");

	for (int i = 0; text2[i] != '\0'; i++) {
		putchar(text2[i]);  // �� ���ھ� ���
		Sleep(30);  // 30 �и��� ���
	}
	Sleep(3000);
	printf("\n\n");
	system("cls");
	Sleep(1500);

	for (int i = 0; text3[i] != '\0'; i++) {
		putchar(text3[i]);  // �� ���ھ� ���
		Sleep(30);  // 30 �и��� ���
	}
	Sleep(3000);
	printf("\n");
	system("cls");


	for (int i = 0; text4[i] != '\0'; i++) {
		putchar(text4[i]);  // �� ���ھ� ���
		Sleep(30);  // 30 �и��� ���
	}
	Sleep(3000);
	printf("\n");
	for (int i = 0; text5[i] != '\0'; i++) {
		putchar(text5[i]);  // �� ���ھ� ���
		Sleep(30);  // 30 �и��� ���
	}
	Sleep(2000);
	printf("\n");
	//1~7 �� ���� ����
	while (1) {
		int temp = randomMap();

		//MST�� ���� ���
		printMapMST(temp);
		Sleep(1000);
		if (heart == 0) break;
		system("cls");
		printf("\n");
		for (int i = 0; text8[i] != '\0'; i++) {
			putchar(text8[i]);  // �� ���ھ� ���
			Sleep(30);  // 30 �и��� ���
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
		putchar(text[i]);  // �� ���ھ� ���
		Sleep(30);  // 30 �и��� ���
	}
}

//� ���� ����� �� �����ϴ� �Լ�2
int randomMap(void) {
	srand(time(NULL));
	int randomNum = rand() % 3 + 1;
	return randomNum;
}

void printMapMST(int randNum) {
	//�� 1 MST
	MST* mst1 = (MST*)malloc(sizeof(MST));
	mst1->node = 9;	mst1->lineSize = 11; mst1->fullLine = 36;
	//�� 1 MST ���� ����(0�� �����ϸ� �ʱ�ȭ�� ����, -1�� �������� ����)
	mst1->line[0] = 0;	mst1->line[1] = 0; mst1->line[2] = 0;	mst1->line[3] = -1;	mst1->line[4] = -1; mst1->line[5] = -1; mst1->line[6] = -1; mst1->line[7] = -1;
	mst1->line[8] = -1; mst1->line[9] = -1; mst1->line[10] = -1; mst1->line[11] = -1; mst1->line[12] = 0; mst1->line[13] = -1; mst1->line[14] = -1;
	mst1->line[15] = -1; mst1->line[16] = 0; mst1->line[17] = -1;  mst1->line[18] = -1; mst1->line[19] = -1;  mst1->line[20] = -1;
	mst1->line[21] = 0; mst1->line[22] = -1; mst1->line[23] = 0;  mst1->line[24] = 0;  mst1->line[25] = -1;
	mst1->line[26] = 0; mst1->line[27] = -1; mst1->line[28] = -1;  mst1->line[29] = 0;
	mst1->line[30] = -1; mst1->line[31] = -1; mst1->line[32] = 0;
	mst1->line[33] = -1; mst1->line[34] = -1;
	mst1->line[35] = -1;

	//�� 2 MST
	MST* mst2 = (MST*)malloc(sizeof(MST));
	mst2->node = 10; mst2->lineSize = 12; mst2->fullLine = 45;
	//�� 2 MST ���� ����(0�� �����ϸ� �ʱ�ȭ�� ����, -1�� �������� ����)
	mst2->line[0] = 0; mst2->line[1] = 0; mst2->line[2] = -1; mst2->line[3] = -1; mst2->line[4] = -1; mst2->line[5] = -1; mst2->line[6] = -1; mst2->line[7] = -1; mst2->line[8] = -1;
	mst2->line[9] = -1; mst2->line[10] = 0; mst2->line[11] = -1; mst2->line[12] = -1; mst2->line[13] = -1; mst2->line[14] = -1; mst2->line[15] = -1; mst2->line[16] = -1;
	mst2->line[17] = 0; mst2->line[18] = -1; mst2->line[19] = 0; mst2->line[20] = -1; mst2->line[21] = -1; mst2->line[22] = -1; mst2->line[23] = -1;
	mst2->line[24] = 0; mst2->line[25] = -1; mst2->line[26] = 0; mst2->line[27] = -1; mst2->line[28] = -1; mst2->line[29] = -1;
	mst2->line[30] = -1; mst2->line[31] = -1; mst2->line[32] = -1; mst2->line[33] = -1; mst2->line[34] = -1;
	mst2->line[35] = 0; mst2->line[36] = -1; mst2->line[37] = -1; mst2->line[38] = -1;
	mst2->line[39] = 0; mst2->line[40] = 0; mst2->line[41] = -1;
	mst2->line[42] = -1; mst2->line[43] = 0;
	mst2->line[44] = 0;

	//�� 3 MST
	MST* mst3 = (MST*)malloc(sizeof(MST));
	mst3->node = 11; mst3->lineSize = 20; mst3->fullLine = 55;
	mst3->line[0] = 0; mst3->line[1] = 0; mst3->line[2] = -1; mst3->line[3] = -1; mst3->line[4] = -1; mst3->line[5] = -1; mst3->line[6] = -1; mst3->line[7] = -1; mst3->line[8] = -1; mst3->line[9] = -1;
	mst3->line[10] = 0; mst3->line[11] = 0; mst3->line[12] = -1; mst3->line[13] = -1; mst3->line[14] = -1; mst3->line[15] = -1; mst3->line[16] = -1; mst3->line[17] = -1; mst3->line[18] = -1;
	mst3->line[19] = 0; mst3->line[20] = 0; mst3->line[21] = 0; mst3->line[22] = -1; mst3->line[23] = -1; mst3->line[24] = -1; mst3->line[25] = -1; mst3->line[26] = -1;
	mst3->line[27] = 0; mst3->line[28] = -1; mst3->line[29] = 0; mst3->line[30] = -1; mst3->line[31] = -1; mst3->line[32] = -1; mst3->line[33] = 0;
	mst3->line[34] = 0; mst3->line[35] = -1; mst3->line[36] = -1; mst3->line[37] = -1; mst3->line[38] = 0; mst3->line[39] = 0;
	mst3->line[40] = -1; mst3->line[41] = 0; mst3->line[42] = -1; mst3->line[43] = 0; mst3->line[44] = -1;
	mst3->line[45] = -1; mst3->line[46] = 0; mst3->line[47] = -1; mst3->line[48] = 0;
	mst3->line[49] = -1; mst3->line[50] = 0; mst3->line[51] = -1;
	mst3->line[52] = -1; mst3->line[53] = 0;
	mst3->line[54] = 0;

	const char* type0 = "�� ���θ� ���� ��� ������ ���θ� ���µ� ���� �ݾ��� ������ ����.";

	if (randNum == 1) {
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
			putchar(type0[i]);  // �� ���ھ� ���
			Sleep(30);  // 30 �и��� ���
		}
		printf("\n");

		randomline(mst1);
		lineWeight(mst1);
		budget = findMST(mst1);
		printf("���� : %d���\n", budget);
		selectMST(mst1, budget);
		Sleep(800);
	}
	if (randNum == 2) {
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
			putchar(type0[i]);  // �� ���ھ� ���
			Sleep(30);  // 30 �и��� ���
		}
		printf("\n");

		randomline(mst2);
		lineWeight(mst2);
		budget = findMST(mst2);
		printf("���� : %d���\n", budget);
		selectMST(mst2, budget);
		Sleep(800);
	}
	if (randNum == 3) {
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
			putchar(type0[i]);  // �� ���ھ� ���
			Sleep(30);  // 30 �и��� ���
		}
		printf("\n");

		randomline(mst3);
		lineWeight(mst3);
		budget = findMST(mst3);
		printf("���� : %d���\n", budget);
		selectMST(mst3, budget);
		Sleep(800);
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
			//printf("[%d] : %d\n",i, mst->line[i]);

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
				printf("[%2d] ���� %c - %c �Ǽ� �� ���� : %d��\n", x, i + 'A', j + 'A', mst->line[x]);
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

	printf("\n��� �������� �ٸ� ��� ������ �� �� �ֵ��� ũ������ �˰������� ����Ͽ� ���ѵ� �������� ���θ� �Ǽ��Ͻÿ�.\n");

	for (i = 0; i < mst->node - 1; i++) {
		for (j = i + 1; j < mst->node; j++) {
			if (mst->line[x] != -1) {
				printf("%c - %c : %d�� ����\n", i + 'A', j + 'A', x);
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
		printf("�Ǽ��� ������ ��ȣ�� �Է�(-1 �Է½� ���θ� �Ǽ�) : ");
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

	for (int i = 0; i < mst->node; ++i) {
		for (int j = i + 1; j < mst->node; ++j) {
			int weight;
			weight = mst->line[i - 1];
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