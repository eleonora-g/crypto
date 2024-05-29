#include "stdio.h"
#include "string.h"
#include <stdint.h>

#define FILE_IN "output.txt"
#define FILE_OUT "input.txt"

uint32_t key = 0;
uint32_t tmp = 0;
uint16_t cnt = 0;
char ch1,ch2 = 0;

int main() {
	FILE *f1, *f2;
	f1 = fopen(FILE_IN, "r");
	f2 = fopen(FILE_OUT, "r");
	while ((ch1 = fgetc(f1)) != EOF) {
		ch2  = fgetc(f2);
		tmp = 0;
		if ((ch1 > 64 && ch1 < 91) || (ch1 > 96 && ch1 < 123)) {
			while (ch1 != ch2) {
				if (++ch2 > (90 + (32 * (ch1 > 96)))) ch2-=26; tmp++; 
				}
			key += tmp;
			cnt++;
		}
	}
	key /= cnt;
	printf("Key: %d\n", key);
	fclose(f1);
	fclose(f2);
	return 0;
}
