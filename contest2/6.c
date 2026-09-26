#include <stdio.h>
#include <stdlib.h>
#define ARR_SIZE 100001
#define NUM_SIZE 100001

int count[NUM_SIZE] = { 0 };


int main() {
	int n, n2, curEl;
	scanf("%d", &n);
	int lenA = n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &curEl);
		if (count[curEl] == 0) {
			count[curEl] = 1;
		}else {
			lenA--;
		}
	}
	scanf("%d", &n2);
	for (int i = 0; i < n2; i++) {
		scanf("%d", &curEl);
		if (count[curEl] > 0) {
			count[curEl] = 0;
			lenA--;
		}
	}
	printf("%d\n", lenA);
	int printed = 0;
	int num = 0;
	while (printed < lenA) {
		if (count[num] == 1) {
			printf("%d ", num);
			printed++;
		}
		num++;
	}
}