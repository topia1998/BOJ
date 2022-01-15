#include <stdio.h>

int max = -1000000001, min = 1000000001, arr[12];
int plus, minus, mul, div, cnt = 0, n;

void max2(int a) {
	if (a > max) max = a;
}

void min2(int a) {
	if (a < min) min = a;
}

void cal(int plus, int minus, int mul, int div, int cnt, int sum) {
	if (cnt == n) {
		max2(sum);
		min2(sum);
	}
	if (plus > 0) cal(plus - 1, minus, mul, div, cnt + 1, sum + arr[cnt]);
	if (minus > 0) cal(plus, minus - 1, mul, div, cnt + 1, sum - arr[cnt]);
	if (mul > 0) cal(plus, minus, mul - 1, div, cnt + 1, sum * arr[cnt]);
	if (div > 0) cal(plus, minus, mul, div - 1, cnt + 1, sum / arr[cnt]);
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	scanf("%d %d %d %d", &plus, &minus, &mul, &div);
	cal(plus, minus, mul, div, 1, arr[0]);

	printf("%d\n%d\n", max, min);
	return 0;
}