#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define A 1000000
int children[A], search[A] = { 0, };

int main()
{
	int n, i, biggest = 0;
	scanf("%d", &n);
	
	for (i = 1; i <= n; i++) scanf("%d", &children[i]);

	for (i = 1; i <= n; i++) {
		int k = children[i];
		search[k] = search[k - 1] + 1;
	}

	for (i = 1; i <= n; i++) {
		if (search[i] > biggest) biggest = search[i];
	}

	printf("%d", n - biggest);

	return 0;
}