#include "stdio.h"
#include "string.h"
#include "stdint.h"

#define FILE_IN "input.txt"
#define VAL(x) (sizeof(x)/sizeof(*x))

uint16_t a[256];
uint32_t cnt;
uint16_t i;
uint8_t ch;
double var;

int main () {
	FILE *fp;
	fp = fopen(FILE_IN, "r");
	for (i = 0; i < VAL(a); ++i)
		a[i] = 0;
	cnt = 0;
	while ((ch = fgetc(fp)) != (uint8_t)EOF) {
		if (ch > 0 && ch < 127) a[ch]++;
	cnt++;
	}
	for (i = 0; i < VAL(a); ++i) {
		if (!a[i] || a[i] == '\n' || a[i] == '\r')
			continue;
		var = a[i];
		var /= cnt;
		printf("%c -> %.3f\n", i, var);
	}
	fclose(fp);
	return 0;
}		
