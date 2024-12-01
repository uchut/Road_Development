#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include "MST.h"

#define LINESIZE 50
#define MAX_VERTICES 100
#define INF 100000000	//무한을 의미
#define NONE_ -1	//존재하지 않음을 의미

//초기 목숨
int heart = 3;
int max_stage = 0;

//MST알고리즘에서 쓰일 점의 개수, (존재하는)간선의 개수, (존재하지 않는 간선 포함)간선의 개수, 간선의 가중치 배열
typedef struct {
	int node;
	int lineSize;
	int fullLine;
	int line[LINESIZE];
} MST;

//각종 함수 선언부, 함수의 메커니즘은 아래 구현부에서 확인
void storyPrint(const char* text);
void intro(void);
int randomMap(void);
void lineWeight(MST* mst);
void randomline(MST* mst);

void printMapMST(int randNum);
void selectMST(MST* mst, int budget);
int numEquals(int num[], int budget, int num2[], MST* mst);

int main(void) {
	intro();	//인트로 스토리 출력 함수
	printf("\n도로 건설에 실패하셨습니다...\n당신의 최고 달성 스테이지: %d", max_stage);
	return 0;
}

//인트로 스토리
void intro(void) {
	printf("바");
	Sleep(30);
	printf("야");
	Sleep(30);
	printf("흐");
	printf("로");
	printf(" 2"); Sleep(30); printf("0"); Sleep(30); printf("2"); Sleep(30); printf("4"); Sleep(30); printf("년");
	Sleep(2000);
	printf("\n");

	const char* text1 = "대한민국의 도시 인프라들은 상당히 낙후 되었고";
	const char* text2 = "이에 따라 정부는 새로운 신도시 계획을 수립하는데...";
	const char* text3 = "당신은 상명시의 도시개발 담당자";
	const char* text4 = "상명시도 재개발 열풍과 정부의 신도시 투자에 따라 새로운 인프라를 구축하려고 한다.";
	const char* text5 = "상명시는 다음 그림과 같이 도심이 형성될 예정이다.";

	const char* text8 = "당신은 새로운 도시로 발령받아서 새로운 도시의 도로 건설을 담당하게 되었습니다.";
	//스토리 출력
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

	// 게임 시작
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

//어떤 맵을 사용할 지 결정하는 함수 (맵 추가되면 숫자 범위 바꾸기)
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

	// 새로운 MST 할당
	globalMST = (MST*)malloc(sizeof(MST));
	if (globalMST == NULL) {
		printf("Memory allocation failed!\n");
		exit(1);
	}
	int current_stage = max_stage + 1;
	printf("현재 스테이지: %d", current_stage);
	const char* type0 = "각 도로를 지을 경우 각각의 도로를 짓는데 들어가는 금액은 다음과 같다.";

	if (randNum == 1) {
		globalMST->node = 9;	globalMST->lineSize = 11; globalMST->fullLine = 36;
		//제 1 MST 간선 유무(0은 존재하며 초기화할 예정, -1은 존재하지 않음)
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
		printf("예산 : %d억원\n", budget);
		selectMST(globalMST, budget);
		Sleep(800);
	}
	if (randNum == 2) {
		globalMST->node = 10; globalMST->lineSize = 12; globalMST->fullLine = 45;
		//제 2 MST 간선 유무
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
		printf("예산 : %d억원\n", budget);
		selectMST(globalMST, budget);
		Sleep(800);
	}
	if (randNum == 3) {
		//제 3 MST 간선 유무
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
		printf("예산 : %d억원\n", budget);
		selectMST(globalMST, budget);
		Sleep(800);
	}
	if (globalMST != NULL) {
		free(globalMST);
		globalMST = NULL;
	}
}

//MST간선들의 가중치를 랜덤으로 설정 하고 lineWeight()를 통해 그 값들을 출력
void randomline(MST* mst) {
	int i = 0;

	//mst구조체에 있는 간선마다 가중치(예산을)값을 넣음
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

//간선별 가중치(예산) 출력
void lineWeight(MST* mst) {
	int i = 0;
	int j = 0, x = 0;
	for (i = 0; i < mst->node - 1; i++) {
		for (j = i + 1; j < mst->node; j++) {
			if (mst->line[x] != -1) {
				printf("[%2d]번 도로 %c - %c 건설 시 예산 : %d억\n", x, i + 'A', j + 'A', mst->line[x]);
			}
			x++;
		}
	}
}

//건설할 도로들의 후보중 최적의 도로들을 유저가 선택하도록 함.
void selectMST(MST* mst, int budget) {
	int i = 0;
	int j = 0, x = 0;
	int num[LINESIZE] = { 0 }, num2[LINESIZE] = { 0 };
	int pass_fail = 0;

	printf("\n어느 마을에서 다른 모든 마을로 갈 수 있도록 제한된 예산으로 도로를 건설하시오.\n");

	for (i = 0; i < mst->node - 1; i++) {
		for (j = i + 1; j < mst->node; j++) {
			if (mst->line[x] != -1) {
				//printf("%c - %c : %d번 도로\n", i + 'A', j + 'A', x);
			}
			x++;
		}
	}

	//간선들의 후보를 num2[]에 담는 코드
	j = 0;
	for (i = 0; i < mst->fullLine; i++) {
		if (mst->line[i] != -1) {
			num2[j] = mst->line[i];
		}
	}

re:
	i = 0;
	while (1) {
		printf("건설할 도로의 번호를 입력 후 엔터(-1 입력시 선택한 모든 도로 선택 확정) : ");
		scanf_s("%d", &num[i]);
		if (num[i] == -1) {
			break;
		}
		else if (mst->line[num[i]] == -1) {
			printf("잘못된 입력입니다.\n처음부터 다시 입력해주세요.\n");
			goto re;
		}
		i++;
	}

	pass_fail = numEquals(num, budget, num2, mst);
	if (pass_fail == -1) {
		heart--;
		printf("< 현재 목숨 : %d >\n", heart);
	}
}

//주어진 예산으로 도로를 건설 할 수 있는지를 확인하여 예산 내로 도로를 건설하지 못하면 -1을, 건설 가능하면 0을 리턴
int numEquals(int num[], int budget, int num2[], MST* mst) {
	int i = 0, sum = 0;
	for (i = 0; i < mst->lineSize && num[i] != -1; i++) {
		if (num[i] == -1) {
			continue;
		}
		sum += mst->line[num[i]];
	}
	printf("%d억원 사용, 예산 : %d\n", sum, budget);
	if (budget == sum) {
		printf("주어진 예산으로 적절하게 도로를 건설하였습니다.\n");
		return 0;
	}
	else if (budget > sum) {
		printf("모든 마을을 잇는 도로를 건설하지 못하였습니다.\n");
		return -1;
	}
	else {
		printf("예산을 초과하여 도로를 건설하였습니다.\n");
		return -1;
	}
}

//간선들의 가중치(예산)을 받아 출력, 이후 최소 예산을 리턴
int findMST(MST* mst) {
	int vertices = 0, edges = 0;
	int budget = 0, i = 0;
	Graph* graph = (Graph*)malloc(sizeof(Graph));

	//mst구조체에 저장된 간선배열을 graph 구조체로 옮김
	for (i = 0; i < mst->fullLine; i++) {
		graph->edge[i].weight = mst->line[i];
	}
	graph->vertices = mst->node;	//점의 개수 옮김
	graph->edges = mst->fullLine;	//존재하지 않는 간선 + 존재하는 간선 개수 옮김

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