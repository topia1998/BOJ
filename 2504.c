#include <stdio.h>
#include <string.h>

int stack[31];
int top = -1;

int IsEmpty() {
	if (top < 0) return 1;
	else return 0;
}

int IsFull() {
	if (top >= 30) return 1;
	else return 0;
}

void push(char val) {
	if (IsFull() != 1) stack[++top] = val;
}

char pop() {
	if (IsEmpty != 1) return stack[top--];
}

int check(int a, int b, int c, int d) {
	if (a == c && b == d) return 1;
	else return 0;
}

int cal(char arr[], int len) {
	int answer = 0, tmp = 1;
	for (int i = 0; i < len; i++) {
		if (arr[i] == '(') {
			push(arr[i]);
			tmp *= 2;
		}
		else if (arr[i] == '[') {
			push(arr[i]);
			tmp *= 3;
		}
		else if (arr[i] == ')') {
			if (IsEmpty == 1 || stack[top] != '(') return 0;
			if (arr[i - 1] == '(') {
				answer += tmp;
				tmp /= 2;
				pop();
			}
			else {
				tmp /= 2;
				pop();
			}
		}
		else if (arr[i] == ']') {
			if (IsEmpty == 1 || stack[top] != '[') return 0;
			if (arr[i - 1] == '[') {
				answer += tmp;
				tmp /= 3;
				pop();
			}
			else {
				tmp /= 3;
				pop();
			}
		}
	}
	if (!IsEmpty()) return 0;
	return answer;
}

int main() {
	char arr[31];
	int len;
	int big_open = 0, big_close = 0, small_open = 0, small_close = 0;

	for (int i = 0; i < 31; i++) {
		scanf("%[^\n]s", arr);
	}
	len = strlen(arr);

	printf("%d\n", cal(arr, len));
	return 0;
}