#include <stdio.h>
#include <stdlib.h>

struct ball {
	int color;
	int idx;
	int size;
};

int compare(const void *a, const void *b) {
	struct ball* p1 = (struct ball*)a;
	struct ball* p2 = (struct ball*)b;
	return p1->size - p2->size;
}



struct s_color {
	int color;
	int sum;
};

int main() {
	
	struct ball s1[20001];
	int N;
	int sum = 0;
	int re[20001] = { 0 };
	int colorsum[20001] = { 0 };


	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		s1[i].idx = i;
		scanf("%d %d", &s1[i].color , &s1[i].size);
	}
	qsort(s1, N, sizeof(struct ball), compare);

	for (int i = 0, j = 0; i < N; i++) {
		for (; s1[i].size > s1[j].size; ++j) {
			sum += s1[j].size;
			colorsum[s1[j].color] += s1[j].size;
		}
		re[s1[i].idx] = sum - colorsum[s1[i].color];
	}
	for (int i = 0; i < N; i++) {
		printf("%d\n", re[i]);
	}
	 
	return 0;
}

