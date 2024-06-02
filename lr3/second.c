#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define FILE_IN "input.txt"
#define FILE_OUT "output.txt"
#define FILE_KEY "key.txt"
#define VAL(X) (sizeof(x)/sizeof(*x))

char ch,key;

int main() {
	FILE *f1, *f2, *fk;
	f1 = fopen(FILE_IN, "r");
	f2 = fopen(FILE_OUT, "w");
	fk = fopen(FILE_KEY, "r");
	while((ch = fgetc(f1)) != EOF) {
		key = fgetc(fk);
		if (key == EOF) break;
		fputc(ch ^ key, f2);
	}
	fclose(f1);
	fclose(f2);
	fclose(fk);
	return 0;
}
