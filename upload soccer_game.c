#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>

int Game_Start();
void Game_TOT();
void Game_MCI();
void Pass();
void Goal();
enum Camp { Zero ,One, Two, Three, Four };

typedef struct attacker {
	char Name[20];
	int	Stats;
	int Num;
	int G_determination;
	int Pass;
}ATT;
ATT AT = {
	"손흥민",92,7,95,90
};

ATT AT2 = {
	"세르지오 아게로",93,10,98,91
};
typedef struct Midfielder {
	char Name[20];
	int	Stats;
	int Num;
	int G_determination;
	int Pass;
}MID;
MID MD = {
	"지오반니 로 셀소",82,18,61,94
};
MID MD2 = {
	"베르나르도 실바",87,20,57,91
};
typedef struct Defender {
	char Name[20];
	int Num;
	int	Stats;
	int Defend;
	int Pass;
}DEF;
DEF DF = {
	"세르지오 레길론",3,84,77,87
};
DEF DF2 = {
	"카일 워커",2,86,82,90
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
	ATT* ATK;
	MID* MDF;
	DEF* DFF;
	KEP* KPP;
}TIM;

int Get_M;
int chose;


TIM Tom;
TIM MCI;

int main() {
	Tom.Name = "Tottenham Hotspur";
	Tom.ATK = &AT;
	Tom.MDF = &MD;
	Tom.DFF = &DF;
	Tom.KPP = &KP;

	Tom.Name = "Manchester City";
	MCI.ATK = &AT2;
	MCI.MDF = &MD2;
	MCI.DFF = &DF2;
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
		printf("공격수\n-- %s --\n 등번호: %d\n 능력치: %d\n 골 결정력: %d\n 패스: %d\n\n", Tom.ATK->Name, Tom.ATK->Num, Tom.ATK->Stats,Tom.ATK->G_determination, Tom.ATK->Pass);
		Sleep(1200);
		printf("미드필더\n-- %s --\n 등번호: %d\n 능력치: %d\n 골 결정력: %d\n 패스: %d\n\n", Tom.MDF->Name, Tom.MDF->Num, Tom.MDF->Stats, Tom.MDF->G_determination, Tom.MDF->Pass);
		Sleep(1200);
		printf("수비수\n-- %s --\n 등번호: %d\n 능력치: %d\n 수비력: %d\n 패스: %d\n\n", Tom.DFF->Name, Tom.DFF->Num, Tom.DFF->Stats, Tom.DFF->Defend, Tom.DFF->Pass);
		Sleep(1200);
		printf("골키퍼\n-- %s --\n 등번호: %d\n 능력치: %d\n 선방능력: %d\n\n", Tom.KPP->Name, Tom.KPP->Num, Tom.KPP->Stats, Tom.KPP->kep_N);

		printf("Manchester City 라인업\n\n");
		Sleep(3000);
		printf("공격수\n-- %s --\n 등번호: %d\n 능력치: %d\n 골 결정력: %d\n 패스: %d\n\n", MCI.ATK->Name, MCI.ATK->Num, MCI.ATK->Stats, MCI.ATK->G_determination, MCI.ATK->Pass);
		Sleep(1200);
		printf("미드필더\n-- %s --\n 등번호: %d\n 능력치: %d\n 골 결정력: %d\n 패스: %d\n\n", MCI.MDF->Name, MCI.MDF->Num, MCI.MDF->Stats ,MCI.MDF->G_determination, MCI.MDF->Pass);
		Sleep(1200);
		printf("수비수\n-- %s --\n 등번호: %d\n 능력치: %d\n 수비력: %d\n 패스: %d\n\n", MCI.DFF->Name, MCI.DFF->Num, MCI.DFF->Stats, MCI.DFF->Defend, MCI.DFF->Pass);
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
	Synthesis_Ch_TOT = Tom.ATK->Stats + Tom.MDF->Stats + Tom.DFF->Stats + Tom.KPP->Stats;
	Synthesis_Ch_MCI= MCI.ATK->Stats + MCI.MDF->Stats + MCI.DFF->Stats + MCI.KPP->Stats;
	Chose_Rand = Synthesis_Ch_MCI + Synthesis_Ch_TOT;
	srand(time(NULL));
	Um = rand() % Chose_Rand;
	if (Synthesis_Ch_MCI > Um) {
		Game_TOT(); return 1;
	}
	else {
		Game_MCI(); return 2;
	}


}
void Game_TOT() {
	
	srand(time(NULL));
	int X = rand() % 2;
	if (X == 0) {
		
	}
	
}
void Game_MCI() {


}
void Pass() {

	 //이곳에서 나는 선수들 포지션을 만들 필요 없이 그냥 선수의 능력을 부여한다는 것을 알았았다.
}//다시 시작한다.
void Goal() {

}
