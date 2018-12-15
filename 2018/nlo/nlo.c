#include <stdlib.h>
#include <stdio.h>

int incircle (int x, int y, int r);

int main () {

	int b;
	int N, M, K;
	int i, j, l;
	int x, y, r;
	int tot = 0;
	// int * field, * ufo;

	scanf("%d %d", &N, &M);
	scanf("%d", &K);

	// int field[N][M] = 0;
	int ufo[K][3];

	for (i = 0; i < K; i++) {
		scanf("%d %d %d", &x, &y, &r);
		ufo[i][0] = r;
		ufo[i][1] = x - 1;
		ufo[i][2] = y - 1;
	}

	for (j = 0; j < N; j++)
	for (l = 0; l < M; l++) {
		b = 0;
		for (i = K-1; i >= 0; i--) {
			r = ufo[i][0];
			x = ufo[i][1];
			y = ufo[i][2];

			b = incircle(x-j, y-l, r);
			if (b) {
				tot += K - 1 - i;
				break;
			}
		}
		if (!b) {
			tot += K;
		}
	}

	printf("%d\n", tot);

	return 0;

}


int incircle (int x, int y, int r) {
	return (x*x + y*y <= r*r);
}