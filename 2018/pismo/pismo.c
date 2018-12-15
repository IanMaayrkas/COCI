#include <stdio.h>
#include <stdlib.h>

int main () {
	int N, i, old, new, min = 2e9, tmp;

	scanf("%d\n", &N)

	scanf("%d", &old);
	for (i = 0; i < N-1 ; i++) {
		scanf("%d", &new);
		tmp = abs(new - old);
		min = tmp < min ? tmp : min;
		old = new;
	}

	printf("%d\n", min);

	return 0;
}