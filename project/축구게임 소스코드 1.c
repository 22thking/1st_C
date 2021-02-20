#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>

int Game_Start();

void Game_TOT();

void Game_MCI();

void Pass();

void Goal();

void Move();

enum Camp { Zero ,One, Two, Three, Four };

typedef struct all_arounder {
	char Name[20];
	int	Stats;
	int Num;
	int G_determination;
	int Pass;
	int Def;

}AAD;

AAD AT[6] = {
	{
		"손흥민",92,7,95,90,49
	},
	{
		"지오반니 로 셀소",82,18,67,94,58
	},
	{
		"세르지오 레길론",3,84,47,87,79
	},
	{
		"세르지오 아게로",93,10,90,91,37
	},
	{
		"베르나르도 실바",87,20,79,91,52
	},
	{
		"카일 워커",2,86,61,90,84
	}

};
AAD* Possession;
AAD* Our_field[5][4]; //몇번째 필드 위에 어떤 선수가 있는가?
AAD* opponent_field[5][4];
typedef struct goalkeeper {
	char Name[20];
	int	Stats;
	int Num;
	int kep_N;
}KEP;

KEP KP = {
	"휴고 요리스",89,1,90
};
KEP KP2 = {
	"에데르손",86,1,86
};

typedef struct Tottenham {
	char* Name;
	AAD* ATK[3];
	KEP *KPP;
}TIM;

int Get_M;
int chose;


TIM Tom;
TIM MCI;

int main() {
	
	Tom.Name = "Tottenham Hotspur";
	Tom.ATK[0] = &AT[0];
	Tom.ATK[1] = &AT[1];
	Tom.ATK[2] = &AT[2];
	Tom.KPP = &KP;

	MCI.Name = "Manchester City";
	MCI.ATK[0] = &AT[3];
	MCI.ATK[1] = &AT[4];
	MCI.ATK[2] = &AT[5];
	MCI.KPP = &KP2;
	
	printf("얼마를 충전하시겠습니까?: ");
	while (1) {
		
		int X = 100;
		scanf("%d", &Get_M);
		if (Get_M <= 0) { printf("잘 못 입력하셨습니다.\n"); }
		else X = 0;
		if (X == 0)break;
	}
	while (1) {
		if (Get_M == 0)break;
		int Money;
		
		printf("현재 잔액: %d원\n\n", Get_M);
		Sleep(1000);
		printf("얼마를 배팅하시겠습니까?: ");
		scanf("%d", &Money);
		if (Money > Get_M||Money==0) {
			printf("숫자를 잘 못 입력하셨습니다.\n"); continue;
		}else Get_M -= Money;
		printf("Tottenham Hotspur 라인업\n\n");
		Sleep(3000);
		printf("공격수\n-- %s --\n 등번호: %d\n 능력치: %d\n 골 결정력: %d\n 패스: %d\n\n", Tom.ATK[0]->Name, Tom.ATK[0]->Num, Tom.ATK[0]->Stats,Tom.ATK[0]->G_determination, Tom.ATK[0]->Pass);
		Sleep(1200);
		printf("미드필더\n-- %s --\n 등번호: %d\n 능력치: %d\n 골 결정력: %d\n 패스: %d\n 수비력: %d\n\n", Tom.ATK[1]->Name, Tom.ATK[1]->Num, Tom.ATK[1]->Stats, Tom.ATK[1]->G_determination, Tom.ATK[1]->Pass, Tom.ATK[1]->Def);
		Sleep(1200);
		printf("수비수\n-- %s --\n 등번호: %d\n 능력치: %d\n 골 결정력: %d\n 패스: %d\n 수비력: %d\n\n", Tom.ATK[2]->Name, Tom.ATK[2]->Num, Tom.ATK[2]->Stats, Tom.ATK[2]->G_determination, Tom.ATK[2]->Pass,Tom.ATK[2]->Def);
		Sleep(1200);
		printf("골키퍼\n-- %s --\n 등번호: %d\n 능력치: %d\n 선방능력: %d\n\n", Tom.KPP->Name, Tom.KPP->Num, Tom.KPP->Stats, Tom.KPP->kep_N);

		printf("Manchester City 라인업\n\n");
		Sleep(3000);
		printf("공격수\n-- %s --\n 등번호: %d\n 능력치: %d\n 골 결정력: %d\n 패스: %d\n 수비력: %d\n\n", MCI.ATK[0]->Name, MCI.ATK[0]->Num, MCI.ATK[0]->Stats, MCI.ATK[0]->G_determination, MCI.ATK[0]->Pass,MCI.ATK[0]->Def);
		Sleep(1200);
		printf("미드필더\n-- %s --\n 등번호: %d\n 능력치: %d\n 골 결정력: %d\n 패스: %d\n 수비력: %d\n\n", MCI.ATK[1]->Name, MCI.ATK[1]->Num, MCI.ATK[1]->Stats, MCI.ATK[1]->G_determination, MCI.ATK[1]->Pass, MCI.ATK[1]->Def);
		Sleep(1200);
		printf("수비수\n-- %s --\n 등번호: %d\n 능력치: %d\n 수비력: %d\n 패스: %d\n 수비력: %d\n\n", MCI.ATK[2]->Name, MCI.ATK[2]->Num, MCI.ATK[2]->Stats, MCI.ATK[2]->G_determination, MCI.ATK[2]->Pass, MCI.ATK[2]->Def);
		Sleep(1200);
		printf("골키퍼\n-- %s --\n 등번호: %d\n 능력치: %d\n 선방능력: %d\n\n", MCI.KPP->Name, MCI.KPP->Num, MCI.KPP->Stats, MCI.KPP->kep_N);

		Sleep(3000); 
		srand(time(NULL));
		int home = rand() % 2;
		if (home == 0)printf("====== Tottenham Hotspur Stadium ======\n\n");
		else printf("====== City of Manchester Stadium ======\n\n");
		printf("========== 토트넘 VS 맨시티 ===========\n\n1. 토트넘  2. 맨시티\n");
		scanf("%d" ,&chose);
		if ((chose == 1 || chose == 2) == 0) { printf("1번 혹은 2번을 입력하시오.\n\n"); continue; }
		if (Game_Start() == 1)printf("토트넘 선공\n");
		else if (Game_Start() == 2)printf("맨시티 선공\n");
	}
	
	printf("돈이 없습니다.");

	

	return 0;
}
int Game_Start() {
	
	int Synthesis_Ch_TOT = 0;
	int Synthesis_Ch_MCI = 0;
	int Chose_Rand = 0;
	int Um;
	for (int i = 0; i < 3; i++) {
		Synthesis_Ch_TOT += Tom.ATK[i]->Stats;
	}
	for (int i = 0; i < 3; i++) {
		Synthesis_Ch_MCI += MCI.ATK[i]->Stats;
	}
	Chose_Rand = Synthesis_Ch_MCI + Synthesis_Ch_TOT;
	srand(time(NULL));
	Um = rand() % Chose_Rand;
	if (Synthesis_Ch_MCI > Um) {
		Game_TOT();
	}
	else {
		Game_MCI();
	}


}
void Game_TOT() {

	Possession = &AT[2];
	Our_field[1][0] = &AT[2];
	Our_field[2][0] = &AT[1];
	Our_field[3][0] = &AT[0];
	opponent_field[1][0] = &AT[3];
	opponent_field[2][0] = &AT[4];
	opponent_field[3][0] = &AT[5];
	srand(time(NULL));
	int X = rand() % 2;
	if (X == 0) {
		Move();
	}
	else if (X == 1) {
		Pass();
	}
	
}
void Game_MCI() {
	
}

void Pass() {

}

void Goal() {

}

void Move() {

	srand(time(NULL));
	int X, Y = 0;
	AAD* CH;
	for (int i = 1; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			if (Possession == Our_field[i][j]) {

				X = rand() % ((Our_field[i][j]->Stats) / 10);
				Y = rand() % ((opponent_field[i][j]->Def) / 10);
				if ((Our_field[i][j]->Stats) + X > (opponent_field[i][j]->Def) + Y) {

					printf("%s 선수가 %s선수를 재치고 %d 구역으로 들어갑니다!!\n", Possession->Name, opponent_field[i][j]->Name, i + 1);
					
				}
				else {

					printf("%s가 공을 빼앗습니다!!!\n", opponent_field[i][j]->Name);

					return;
				}
			}
		}
	}
}