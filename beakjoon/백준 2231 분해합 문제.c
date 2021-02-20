#include <stdio.h>

int Depo(int x);
int main() {
	int get_n;
	scanf("%d", &get_n);


	
	for (int j = 1; j <= get_n; j++) {
		if (Depo(j) == get_n) {
			printf("%d", j);
			goto End;
		}
	}
	printf("0");
	End:

	

	return 0;
}
int Depo(int x) {
	int copy = x;
	int sum = x;
	while (copy!= 0) {
		sum += copy % 10;
		copy /= 10;
	}
	return sum;
}


