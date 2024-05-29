#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define FILE_IN "input.txt"
#define CNT 6000

unsigned int a = 0;

int main() {
	FILE *fp;
	fp = fopen(FILE_IN, "w");
	while (!a) {
		printf("size: ");
		scanf("%d", &a);
	}
	srand(time(NULL));
	for(int i = 0; i < CNT; ++i) {
		fputc((rand() % a), fp);
	}
	fclose(fp);
	return 0;
}
