#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 51

int chicken_n = 0;
int home_n = 0;
int home[MAX * 2] = { 0 };
int chicken[13] = { 0 };
int M;
int MIN = 999999999;
int isused[14] = { 0 }; //사용했나 안 했나?
int a[14] = { 0 }; //치킨집 고르는 배열
int Last =0; 
int result = 99999999999;

int distance(int X, int Y) {		
	int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	int sum = 0;
	x1 = X / 100; y1 = X % 100;
	x2 = Y / 100; y2 = Y % 100;
	sum = abs(x1-x2) + abs(y1-y2);
	return sum;
}
void DFS(int t, int k) //
{
	if (t == M)
	{	
		Last = 0;
		for (int i = 0; i < home_n; i++) {
			MIN = 999999999;
			for (int j = 0; j < M; j++) {
				if (MIN > distance(home[i], chicken[a[j]]))
					MIN = distance(home[i], chicken[a[j]]);	
			}
			Last += MIN;
		}
		if (result > Last) {
			
			result = Last;
		}
		return;
	}
	for (int i = k; i < chicken_n; i++)
	{
		if (isused[i] == 0)
		{
			isused[i] = 1;
			a[t] = i;
			DFS(t + 1, i + 1);
			isused[i] = 0;
		}
	}
}
int main() {
	
	int N;
	scanf("%d %d", &N, &M);
	int get[53][53];
	
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &get[i][j]);
			if (get[i][j] == 1) {
				home[home_n] = (i * 100) + j; //i는 행임 j는 열이고
				home_n++;
			}
			if (get[i][j] == 2) {
				chicken[chicken_n]= (i * 100) + j;
				chicken_n++;
			}

		}
	}
	DFS(0, 0);
	printf("%d", result);

	return 0;
}