#include "stdio.h"
#include "string.h"
#include <stdint.h>

#define FILE_IN "output.txt"
#define FILE_OUT "input_reload.txt"

int key = 0;
char ch = 0;
uint8_t a = 0;

int main () {
	FILE *f1, *f2;
	f1 = fopen(FILE_IN, "r");
	f2 = fopen(FILE_OUT, "w");
	while (!key || key > 25) {
		printf("enter key:");
		scanf("%d", &key);
	}
	while ((ch = fgetc(f1)) != EOF) {
		a = ch;
		if (a > 64 && a < 91) {
			a -= key;
			if (a < 65) a += 26;
		}
		else if (a > 96 && a < 123) {
			a -= key;
			if (a < 97) a+=26;
		}
		fputc(a,f2);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}
