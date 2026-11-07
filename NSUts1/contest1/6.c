#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);
	int min = 0;
	int min_n = 1;
	int max = 0;
	int max_n = 1;
	for (int i = 1; i <= n; ++i) {
		int cur;
		scanf("%d", &cur);
		if (i == 1) {
			min = cur;
			max = cur;
		}
		else if (cur > max) {
			max = cur;
			max_n = i;
		}
		else if (cur < min) {
			min = cur;
			min_n = i;
		}
	}
	printf("%d %d %d %d", min, min_n, max, max_n);
}