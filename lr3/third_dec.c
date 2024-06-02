#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define FILE_IN "ouput.txt"
#define FILE_OUT "output_dec.txt"

uint16_t s[256];
char key[256];
uint16_t k, i, j;
uint8_t len;
char ch;

int main() {
	FILE *f1,*f2;
	f1 = fopen(FILE_IN, "r");
	f2 = fopen(FILE_OUT, "w");
	for (i = 0; i < (sizeof(key)/sizeof(*key)); ++i) key[i] = '\0';
	while ((len = strlen(key)) == 0) {
		printf("key: ");
		scanf("%s", key);
	}
	for (i = 0; (i + len) < 256; ++i) key[len+i] = key[i];
	for (i = 0; i < 256; ++i) s[i] = i;
	for (i = 0, j = 0; i < 256; ++i) {
		j = (j + s[i] + key[i % len])% 256;
		k = s[i];
		s[i] = s[j];
		s[j] = k;
	}
	i = 0;
	j = 0;
	while ((ch = fgetc(f1)) != EOF) {
		i = (i + 1) % 256;
		j = (j + s[i]) % 256;
		k = s[i];
		s[i] = s[j];
		s[j] = k;
		k = (s[i] + s[j]) % 256;
		fputc(s[k] ^ ch, f2);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}
