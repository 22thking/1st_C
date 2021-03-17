#include <stdio.h>
#include <stdlib.h>

#define SIX 6

int dice[6] = { 1,2,3,4,5,6 }; 
int indexDice[4][6]= { {3,1,0,5,4,2},{2,1,5,0,4,3},{1,5,2,3,0,4},{4,0,2,3,5,1} }; //동 서 북 남
int nowIndexDice[5][6] = { {0,1,2,3,4,5 },{0,1,2,3,4,5 },{0,1,2,3,4,5 },{0,1,2,3,4,5 },{ 0,1,2,3,4,5 } };

void firstDice(int index) {

	int randumN = 0;
	int nowDiceDir[5] = { 0 };
	int tmpdice[6] = { 0 };
	int diceDir = 5;
	randumN = rand() % 6+1;
	int seq = 0;

	while (seq<randumN) {
		int d = rand() % 4;
		
		if (d == diceDir)
			continue;
		for (int z = 0; z < 6; z++)
		{
			tmpdice[z] = nowIndexDice[index][z];
		}
		for (int z = 0; z < 6; z++)
		{
			nowIndexDice[index][z] = tmpdice[indexDice[d][z]];
		}
		printf("%d *\n", dice[nowIndexDice[index][5]]);
		seq++;
	}
	printf("%d\n", dice[nowIndexDice[index][5]]);
	return;
}

int main() {

	srand(time(NULL));
	int choseStop[SIX];

	for (int i = 0; i < 5; i++)
	{
		firstDice(i);
	}
	for (int i = 0; i < 5; i++) {
		printf("%d ", dice[nowIndexDice[i][5]]);
	}
	printf("\n");
	int N;
	scanf("%d",&N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d",&choseStop[i]);
	}
	for (int i = 0; i < N; i++) {
		firstDice(choseStop[i]);
	}
	
	for (int i = 0; i < 5; i++) {
		printf("%d ", dice[nowIndexDice[i][5]]);
	}
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &choseStop[i]);
	}
	for (int i = 0; i < N; i++) {
		firstDice(choseStop[i]);
	}

	for (int i = 0; i < 5; i++) {
		printf("%d ", dice[nowIndexDice[i][5]]);
	}
	
	
	return 0;
}