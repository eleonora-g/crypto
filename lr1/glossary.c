#include "stdio.h"
#include "string.h"
#include <stdint.h>

#define FILE_IN "output.txt"
#define COUNTOF(x) ((sizeof(x))/(sizeof(*x)))

const char* glossary[] = {"my", "you", "to", "very", "i", "this"};

uint8_t i, key;
uint8_t wrd[25];
char ch, w[10];

int main () {
	FILE *f1;
	for (i = 0; i < COUNTOF(wrd); ++i) wrd[i] = 0;
	for (key = 1; key < 26; ++key) {
		f1 = fopen(FILE_IN, "r");
		for (i = 0; i < COUNTOF(w); ++i) w[i] = '\0';
		while (1) {
		ch = fgetc(f1);
		if (ch == ' ' || ch == '\r' || ch == '\n' || ch == EOF || ch == ',' || ch == '.') {
			if(strlen(w)) {
				for (i = 0; i < COUNTOF(glossary); ++i)
				if (strcmp(w, glossary[i]) == 0) {wrd[key - 1]++; break;}
				}
			for (i = 0; i < COUNTOF(w); ++i) w[i] = '\0';
			if (ch == EOF) break;
		}
		else {
			if (ch > 64 && ch < 91) ch += 32;
			if (ch > 96 && ch < 123) {
				ch -= key;
				if (ch < 97) ch += 26;
				w[strlen(w)] = ch;
			}
		}
	}
	fclose(f1);
	}
	key = 0;
	ch = 0;
	for (i = 0; i < COUNTOF(wrd); ++i) {
		if (wrd[i] > ch) {
			ch = wrd[i];
			key = i + 1;
		}
	}
	if (key) printf("Key: %d\n", key);
	else printf("failed\n");
	return 0;
}
