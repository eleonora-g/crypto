#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define FILE_OUT "key.txt"
#define CNT 6000

unsigned int a = 0;

int main() {
	FILE *f;
	f = fopen(FILE_OUT, "w");
	while (!a) {
		printf("size: ");
		scanf("%d", &a);
	}
	srand(time(NULL));
	for(int i = 0; i < CNT; ++i) {
		fputc((rand() % a), f);
	}
	fclose(f);
	return 0;
}
