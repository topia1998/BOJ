#include <stdio.h>
#include <stdlib.h>

void fun(int arr[], int n, int s) {
	int start = 0, end = 0;
	int sum = arr[start];
	int len = 1, min_len = 100001;
	while (end != n && start != n) {
		if (sum < s) {
			sum += arr[++end];
			len++;
		}
		else if (sum >= s) {
			sum -= arr[start++];
			if (min_len > len) min_len = len;
			len--;
		}
	}
	if (min_len == 100001) printf("0\n");
	else printf("%d\n", min_len);
}

int main() {
	int n, s;
	int sum, min_len = 100001, len = 0;
	scanf("%d %d", &n, &s);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	fun(arr, n, s);
	return 0;
}