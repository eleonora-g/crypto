#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#define FILE_IN "input.txt"
#define VAL(x) (sizeof(x)/sizeof(*x))

uint16_t a[256];
uint32_t cnt = 0;
uint8_t ch;
double var, sum = 0;

int main () {
	FILE *fp;
	fp = fopen(FILE_IN, "r");
	for (int i = 0; i < VAL(a); ++i)
		a[i] = 0;
	while ((ch = fgetc(fp)) != (uint8_t)EOF) {
		if (ch > 0 && ch < 127) a[ch]++;
		cnt++;
	}
	for (int i = 0; i < VAL(a); ++i) {
		if (!a[i] || a[i] == '\n' || a[i] == '\r')
			continue;
		var = a[i];
		var /= cnt;
		sum += var * (log(var)/log(2));
	}
	printf("%.3f\n", -sum);
	fclose(fp);
	return 0;
}
