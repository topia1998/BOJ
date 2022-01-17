#include <stdio.h>

int check(int n) {
	int i;
	if (n == 1) return 1;
	else if (n == 2) return 0;
	for (i = 2; i <= (n / 2 + 1); i++) {
		if (n % i == 0) return 1;
	}
	return 0;
}

int main() {
	int low, high, i, sum = 0, min = 10001, chk, cnt = 0;
	scanf("%d %d", &low, &high);
	for (i = low; i <= high; i++) {
		chk = check(i);
		if (chk == 0) {
			sum += i;
			if (i <= min) min = i;
			cnt++;
		}
	}
	if (cnt == 0) printf("-1\n");
	else {
		printf("%d\n", sum);
		printf("%d\n", min);
	}
	return 0;
}