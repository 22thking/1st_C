#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>

void Game_Start();

void Pass_TOT();

void Goal_TOT();

void Move_TOT();

void Pass_MCI();

void Goal_MCI();

void Move_MCI();

void reset();

int start_time = 0;

typedef struct all_arounder {
	char Name[20];
	int	Stats;
	int Num;
	int G_determination;
	int Pass;
	int Def;
	int Possession;      //공을 가지고 있는가?
	int x, y;           //좌표 평면 x,y
}AAD;

AAD AT[6] = {
	{
		"손흥민",92,7,95,90,49,0,1,2
	},
	{
		"해리 케인",93,10,98,94,58,0,1,1
	},
	{
		"가레스 베일",86,11,77,85,49,0,1,0
	},
	{
		"리아드 마레즈",85,26,80,93,49,0,3,2
	},
	{
		"세르히오 아구에로",94,10,97,91,52,0,3,1
	},
	{
		"라힘 스털링",91,7,86,82,39,0,3,0
	}

};

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
	KEP* KPP;
	int have_ball;
	int score;
}TIM;

int Get_M;
int chose;


TIM Tom;
TIM MCI;

int main() {

	srand(time(NULL));
	Tom.ATK[0] = &AT[0];
	Tom.ATK[1] = &AT[1];
	Tom.ATK[2] = &AT[2];
	Tom.score = 0;
	Tom.KPP = &KP;


	MCI.ATK[0] = &AT[3];
	MCI.ATK[1] = &AT[4];
	MCI.ATK[2] = &AT[5];
	MCI.score = 0;
	MCI.KPP = &KP2;

	printf("얼마를 충전하시겠습니까?: ");
	while (1) {

		int X = 100;
		scanf("%d", &Get_M);
		if (Get_M <= 0) { printf("잘 못 입력하셨습니다.\n"); }
		else 
			X = 0;
		if (X == 0)break;
	}
	while (1) {
		if (Get_M == 0)break;
		int Money;

		printf("현재 잔액: %d원\n\n", Get_M);
		Sleep(1000);
		printf("얼마를 배팅하시겠습니까?: ");
		scanf("%d", &Money);
		if (Money > Get_M || Money == 0) {
			printf("숫자를 잘 못 입력하셨습니다.\n");  
			Sleep(1200);
			system("cls"); continue;
		}
		else Get_M -= Money;
		printf("Tottenham Hotspur 라인업\n\n");
		Sleep(3000);
		printf("LW\n-- %s --\n 등번호: %d\n 능력치: %d\n 골 결정력: %d\n 패스: %d\n 수비력: %d\n\n", Tom.ATK[0]->Name, Tom.ATK[0]->Num, Tom.ATK[0]->Stats, Tom.ATK[0]->G_determination, Tom.ATK[0]->Pass, Tom.ATK[0]->Def);
		Sleep(1200);
		printf("ST\n-- %s --\n 등번호: %d\n 능력치: %d\n 골 결정력: %d\n 패스: %d\n 수비력: %d\n\n", Tom.ATK[1]->Name, Tom.ATK[1]->Num, Tom.ATK[1]->Stats, Tom.ATK[1]->G_determination, Tom.ATK[1]->Pass, Tom.ATK[1]->Def);
		Sleep(1200);
		printf("RW\n-- %s --\n 등번호: %d\n 능력치: %d\n 골 결정력: %d\n 패스: %d\n 수비력: %d\n\n", Tom.ATK[2]->Name, Tom.ATK[2]->Num, Tom.ATK[2]->Stats, Tom.ATK[2]->G_determination, Tom.ATK[2]->Pass, Tom.ATK[2]->Def);
		Sleep(1200);
		printf("GK\n-- %s --\n 등번호: %d\n 능력치: %d\n 선방능력: %d\n\n", Tom.KPP->Name, Tom.KPP->Num, Tom.KPP->Stats, Tom.KPP->kep_N);

		printf("Manchester City 라인업\n\n");
		Sleep(3000);
		printf("RW\n-- %s --\n 등번호: %d\n 능력치: %d\n 골 결정력: %d\n 패스: %d\n 수비력: %d\n\n", MCI.ATK[0]->Name, MCI.ATK[0]->Num, MCI.ATK[0]->Stats, MCI.ATK[0]->G_determination, MCI.ATK[0]->Pass, MCI.ATK[0]->Def);
		Sleep(1200);
		printf("ST\n-- %s --\n 등번호: %d\n 능력치: %d\n 골 결정력: %d\n 패스: %d\n 수비력: %d\n\n", MCI.ATK[1]->Name, MCI.ATK[1]->Num, MCI.ATK[1]->Stats, MCI.ATK[1]->G_determination, MCI.ATK[1]->Pass, MCI.ATK[1]->Def);
		Sleep(1200);
		printf("LW\n-- %s --\n 등번호: %d\n 능력치: %d\n 골 결정력: %d\n 패스: %d\n 수비력: %d\n\n", MCI.ATK[2]->Name, MCI.ATK[2]->Num, MCI.ATK[2]->Stats, MCI.ATK[2]->G_determination, MCI.ATK[2]->Pass, MCI.ATK[2]->Def);
		Sleep(1200);
		printf("GK\n-- %s --\n 등번호: %d\n 능력치: %d\n 선방능력: %d\n\n", MCI.KPP->Name, MCI.KPP->Num, MCI.KPP->Stats, MCI.KPP->kep_N);

		Sleep(3000);
		int home = rand() % 2;
		if (home == 0)
			printf("====== Tottenham Hotspur Stadium ======\n\n");
		else printf("====== City of Manchester Stadium ======\n\n");
		printf("========== 토트넘 VS 맨시티 ===========\n\n1. 토트넘  2. 맨시티 3. 무승부\n\n");
		double bet_NT = 3;
		double bet_NM = 3;
		double bet_ND = 0;
		double UMJUN = (rand() % 100) * 0.01;
		if (home == 0) { 
			bet_NT -= UMJUN;
			bet_NM += UMJUN;
			bet_ND += bet_NT + UMJUN*3;
		}
		else {
			bet_NM -= UMJUN;
			bet_NT += UMJUN;
			bet_ND += bet_NM + UMJUN*3;
		}
		
		printf("배당: %.2f %.2f %.2f\n", bet_NT, bet_NM, bet_ND);
		scanf("%d", &chose);
		double Nice = 0;
		if ((chose == 1 || chose == 2|| chose ==3 ) == 0) { printf("1번 2번 3번 중 하나를 입력하시오.\n\n"); continue; }
		if (chose == 1)Nice = bet_NT;
		else if (chose == 2)Nice = bet_NM;
		else if (chose == 3)Nice = bet_ND;
		int discri = 0;
		Game_Start();
		while (1) {
			if (start_time > 49) {
				
				printf("================= 경기종료! ===============\n");
				printf("Tottenham Hotspur  %d:%d  Manchester City\n", Tom.score, MCI.score);
				
				Sleep(15000);
				system("cls");
				if (Tom.score > MCI.score) discri = 1;
				else if (Tom.score < MCI.score) discri = 2;
				else if (Tom.score == MCI.score) discri = 3;
				if (discri == chose) {
					Get_M += Nice * Money;
					printf("예측 성공\n\n%.2f 배당 성공\n%.0f 추가!!\n", Nice , Nice*Money );
				}
				else
					printf("예측 실패\n\n");
				
				start_time = 0;
				Tom.score = 0;
				MCI.score = 0;
				break;
			}
			else {
				Move_TOT();
				Move_MCI();
			}
		}

	}
	//printf("돈이 없습니다.");




	return 0;
}

void Game_Start() {

	int Synthesis_Ch_TOT = 0;
	int Synthesis_Ch_MCI = 0;
	int Chose_Rand = 0;
	int Um = 0;
	for (int i = 0; i < 3; i++) {
		Synthesis_Ch_TOT += Tom.ATK[i]->Stats;
	}
	for (int i = 0; i < 3; i++) {
		Synthesis_Ch_MCI += MCI.ATK[i]->Stats;
	}
	Chose_Rand = Synthesis_Ch_MCI + Synthesis_Ch_TOT;
	Um = rand() % Chose_Rand;
	if (Synthesis_Ch_MCI > Um) {
		Tom.have_ball = 1;
		Tom.ATK[1]->Possession = 1;
		printf("토트넘 선공\n");
		Sleep(3000);
		system("cls");
		printf("경기 시작합니다!!!\n");
		Sleep(3000);
	}
	else {
		MCI.have_ball = 1;
		MCI.ATK[1]->Possession = 1;
		printf("맨시티 선공\n");
		Sleep(3000);
		system("cls");
		printf("경기 시작합니다!!!\n");
		Sleep(3000);
	}


}


void Pass_TOT() {

	for (int i = 0; i < 3; i++) {

		if (Tom.ATK[i]->Possession == 1) {
			start_time++;
			int Discrimination = rand() % 3;
			if (i != Discrimination) {
				Tom.ATK[i]->Possession = 0;
				Tom.ATK[Discrimination]->Possession = 1;
				printf("%s선수가 %s선수에게 패스합니다.\n\n", Tom.ATK[i]->Name, Tom.ATK[Discrimination]->Name);
				Sleep(1000);
			}
			else if (i == Discrimination) continue;

		}
	}
}

void Goal_TOT() {

	for (int i = 0; i < 3; i++) {
		if (Tom.ATK[i]->Possession == 1) {
			if (Tom.ATK[i]->x == 3) {
				int X1, X2 = 0;
				X1 = (rand() % Tom.ATK[i]->G_determination) - 40;
				X2 = rand() % MCI.KPP->kep_N;
				printf("%s 선수가 중거리 슛을 쏩니다!!\n", Tom.ATK[i]->Name);
				Sleep(1500);
				if (X1 > X2) {
					start_time++;
					Tom.score++;
					printf("%s 선수가 골을 넣습니다!!! 대단합니다!\n\n", Tom.ATK[i]->Name);
					printf("Tottenham Hotspur  %d:%d  Manchester City\n\n", Tom.score, MCI.score);
					Tom.have_ball = 0;
					MCI.have_ball = 1;
					Tom.ATK[i]->Possession = 0;
					MCI.ATK[1]->Possession = 1;
					Sleep(3000);
					reset();
				}
				else if (X1 <= X2) {
					start_time++;
					printf("%s 선수 공을 막습니다!!!!\n\n", MCI.KPP->Name);
					Sleep(1000);
					Tom.have_ball = 0;
					MCI.have_ball = 1;
					Tom.ATK[i]->Possession = 0;
					MCI.ATK[1]->Possession = 1;
				}
			}

			else if (Tom.ATK[i]->x == 4) {
				int X1, X2 = 0;
				X1 = (rand() % Tom.ATK[i]->G_determination);
				X2 = rand() % MCI.KPP->kep_N;
				printf("%s 선수 결정적인 기회!! 슛을 쏩니다!!\n", Tom.ATK[i]->Name);
				Sleep(1000);
				if (X1 > X2) {
					start_time++;
					Tom.score++;
					printf("%s 선수가 골을 넣습니다!!!\n\n", Tom.ATK[i]->Name);
					printf("Tottenham Hotspur  %d:%d  Manchester City\n\n", Tom.score, MCI.score);
					Tom.have_ball = 0;
					MCI.have_ball = 1;
					Tom.ATK[i]->Possession = 0;
					MCI.ATK[1]->Possession = 1;
					Sleep(3000);
					reset();
				}
				else if (X1 <= X2) {
					start_time++;
					printf("%s 선수 공을 막습니다!!!!\n\n", MCI.KPP->Name);
					Sleep(1000);
					Tom.have_ball = 0;
					MCI.have_ball = 1;
					Tom.ATK[i]->Possession = 0;
					MCI.ATK[1]->Possession = 1;
				}
			}
		}

	}
}

void Move_TOT() {

	if (Tom.have_ball == 1) {
		for (int i = 0; i < 3; i++) {
			if (Tom.ATK[i]->Possession == 1) {
				if (Tom.ATK[i]->x == 4)
					Goal_TOT();
				else if (Tom.ATK[i]->x == 3) {
					int Discrimination = rand() % 3;
					if (Discrimination == 0)Pass_TOT();
					else if (Discrimination == 1)Tom.ATK[i]->x++;
					else if (Discrimination == 2)Goal_TOT();
				}
				int Discrimination = rand() % 2;
				if (Discrimination == 0)Pass_TOT();
				else if (Discrimination == 1)Tom.ATK[i]->x++;
			}
			else if (Tom.ATK[i]->Possession == 0) {
				if (Tom.ATK[i]->x == 4)continue;

				int Discrimination = rand() % 2;
				if (Discrimination == 0)
					Tom.ATK[i]->x++;
				else if (Discrimination == 1)
					break;

			}
		}
	}

	else if (Tom.have_ball == 0) {
		int x1, y1 = 0;
		int P_M = 0;
		for (int i = 0; i < 3; i++) {
			if (MCI.ATK[i]->Possession == 1) {
				x1 = MCI.ATK[i]->x;
				y1 = MCI.ATK[i]->y;
				P_M = i;
			}
		}
		for (int i = 0; i < 3; i++) {
			if ((Tom.ATK[i]->x == x1 && Tom.ATK[i]->y == y1) == 1) {

				int Ch1, Ch2 = 0;
				Ch1 = rand() % Tom.ATK[i]->Def;
				Ch2 = rand() % MCI.ATK[i]->Stats;

				if (Ch1 >= Ch2) {
					start_time++;
					Tom.have_ball = 1;
					MCI.have_ball = 0;
					Tom.ATK[i]->Possession = 1;
					MCI.ATK[P_M]->Possession = 0;
					printf("%s 선수가 %s 선수 공을 빼앗습니다!\n\n", Tom.ATK[i]->Name, MCI.ATK[P_M]->Name);
					Sleep(1000);
					break;
				}
				else {
					start_time++;
					if (Tom.ATK[i]->x > 1) {
						Tom.ATK[i]->x--;
					}
					else continue;
				}

			}
			else {
				if (Tom.ATK[i]->x > 1)
					Tom.ATK[i]->x--;
				else continue;
			}


		}
	}


}
void reset() {
	Tom.ATK[0]->x = 1;
	Tom.ATK[1]->x = 1;
	Tom.ATK[2]->x = 1;
	MCI.ATK[0]->x = 3;
	MCI.ATK[1]->x = 3;
	MCI.ATK[2]->x = 3;
}

void Pass_MCI() {

	for (int i = 0; i < 3; i++) {

		if (MCI.ATK[i]->Possession == 1) {
			start_time++;
			int Discrimination = rand() % 3;
			if (i != Discrimination) {
				MCI.ATK[i]->Possession = 0;
				MCI.ATK[Discrimination]->Possession = 1;
				printf("%s선수가 %s선수에게 패스합니다.\n\n", MCI.ATK[i]->Name, MCI.ATK[Discrimination]->Name);
				Sleep(1000);
			}
			else if (i == Discrimination) continue;

		}
	}
}

void Goal_MCI() {
	for (int i = 0; i < 3; i++) {
		if (MCI.ATK[i]->Possession == 1) {
			if (MCI.ATK[i]->x == 1) {
				int X1, X2 = 0;
				X1 = (rand() % MCI.ATK[i]->G_determination) - 35;
				X2 = rand() % Tom.KPP->kep_N;
				printf("%s 선수가 중거리 슛을 쏩니다!!\n", MCI.ATK[i]->Name);
				Sleep(1500);
				if (X1 > X2) {
					start_time++;
					MCI.score++;
					printf("%s 선수가 골을 넣습니다!!! 대단한 골이 나왔습니다!!!\n\n", MCI.ATK[i]->Name);
					printf("Tottenham Hotspur  %d:%d  Manchester City\n\n", Tom.score, MCI.score);
					MCI.have_ball = 0;
					Tom.have_ball = 1;
					MCI.ATK[i]->Possession = 0;
					Tom.ATK[1]->Possession = 1;
					Sleep(3000);
					reset();
				}
				else if (X1 <= X2) {
					start_time++;
					printf("%s 선수 공을 막습니다!!!!\n\n", Tom.KPP->Name);
					Sleep(1000);
					MCI.have_ball = 0;
					Tom.have_ball = 1;
					MCI.ATK[i]->Possession = 0;
					Tom.ATK[1]->Possession = 1;

				}
			}

			else if (MCI.ATK[i]->x == 0) {
				int X1, X2 = 0;
				X1 = (rand() % MCI.ATK[i]->G_determination);
				X2 = rand() % Tom.KPP->kep_N;
				printf("%s 선수 결정적인 기회!! 슛을 쏩니다!!\n", Tom.ATK[i]->Name);
				Sleep(1000);
				if (X1 > X2) {
					start_time++;
					MCI.score++;
					printf("%s 선수가 골을 넣습니다!!!\n\n", MCI.ATK[i]->Name);
					printf("Tottenham Hotspur  %d:%d  Manchester City\n\n", Tom.score, MCI.score);
					MCI.have_ball = 0;
					Tom.have_ball = 1;
					MCI.ATK[i]->Possession = 0;
					Tom.ATK[1]->Possession = 1;
					Sleep(3000);
					reset();
				}
				else if (X1 <= X2) {
					start_time++;
					printf("%s 선수 공을 막습니다!!!!\n\n", Tom.KPP->Name);
					Sleep(1000);
					MCI.have_ball = 0;
					Tom.have_ball = 1;
					MCI.ATK[i]->Possession = 0;
					Tom.ATK[1]->Possession = 1;
				}
			}
		}

	}
}

void Move_MCI() {

	if (MCI.have_ball == 1) {
		for (int i = 0; i < 3; i++) {
			if (MCI.ATK[i]->Possession == 1) {
				if (MCI.ATK[i]->x == 1)Goal_MCI();
				else if (MCI.ATK[i]->x == 2) {
					int Discrimination = rand() % 3;
					if (Discrimination == 0)Pass_MCI();
					else if (Discrimination == 1)MCI.ATK[i]->x--;
					else if (Discrimination == 2)Goal_MCI();
				}
				int Discrimination = rand() % 2;
				if (Discrimination == 0)Pass_MCI();
				else if (Discrimination == 1)MCI.ATK[i]->x--;
			}
			else if (MCI.ATK[i]->Possession == 0) {
				if (MCI.ATK[i]->x == 1)continue;

				int Discrimination = rand() % 2;
				if (Discrimination == 0)
					MCI.ATK[i]->x--;
				else if (Discrimination == 1)
					break;

			}
		}
	}

	else if (MCI.have_ball == 0) {
		int x1, y1 = 0;
		int P_M = 0;
		for (int i = 0; i < 3; i++) {
			if (Tom.ATK[i]->Possession == 1) {
				x1 = Tom.ATK[i]->x;
				y1 = Tom.ATK[i]->y;
				P_M = i;
			}
		}
		for (int i = 0; i < 3; i++) {
			if ((MCI.ATK[i]->x == x1 && MCI.ATK[i]->y == y1) == 1) {

				int Ch1, Ch2 = 0;
				Ch1 = rand() % MCI.ATK[i]->Def;
				Ch2 = rand() % Tom.ATK[i]->Stats;

				if (Ch1 >= Ch2) {
					start_time++;
					MCI.have_ball = 1;
					Tom.have_ball = 0;
					printf("%s 선수가 %s 선수 공을 빼앗습니다!\n\n", MCI.ATK[i]->Name, Tom.ATK[P_M]->Name);
					MCI.ATK[i]->Possession = 1;
					Tom.ATK[P_M]->Possession = 0;

					Sleep(1000);
					break;
				}
				else {
					if (MCI.ATK[i]->x < 4) {
						MCI.ATK[i]->x++;
					}
					else continue;
				}

			}
			else {
				if (MCI.ATK[i]->x < 4)
					MCI.ATK[i]->x++;
				else continue;
			}


		}
	}
}