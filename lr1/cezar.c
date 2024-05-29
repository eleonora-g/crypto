#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define FILE_IN "input.txt"
#define FILE_OUT "output.txt"

int key = 0;
char ch = 0;
int a = 0;

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
			a += key;
			if (a > 90)
			a -= 26;
		}
		else if (a > 96 && a < 123) {
			a += key;
			if (a > 122) a-=26;
		}
		fputc(a,f2);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}
