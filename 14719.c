#include <stdio.h>
#include <stdlib.h>

int main() {
	int width, height, cnt = 0, sum = 0, tmp = 0, max = 0;
	int lmax, rmax;
	scanf("%d %d", &height, &width);
	int* arr = (int*)malloc(sizeof(int) * width);
	for (int i = 0; i < width; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] != 0) cnt++;
	}
	for (int i = 0; i < width; i++) {
		lmax = 0; rmax = 0;
		for (int x = i; x >= 0; x--) {
			if (arr[i] < arr[x] && lmax < arr[x]) lmax = arr[x];
		}
		for (int y = i; y < width; y++) {
			if (arr[i] < arr[y] && rmax < arr[y]) rmax = arr[y];
		}
		if (lmax != 0 && rmax != 0) {
			tmp = (lmax < rmax) ? lmax : rmax;
			sum += tmp - arr[i];
		}
		else {
			cnt++;
		}
	}
	if (cnt == width) printf("0\n");
	else printf("%d\n", sum);
	return 0;
}