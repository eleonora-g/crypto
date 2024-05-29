#include "stdio.h"
#include "string.h"

#define FILE_IN "output.txt"
#define FILE_OUT "all.txt"

int key = 0;
char ch = 0;

int main () {
	FILE *f1, *f2;
	f2 = fopen(FILE_OUT, "w");
	for (key = 1; key < 26; ++key) {
		f1 = fopen(FILE_IN, "r");
		fprintf(f2, "key = %d \n", key);
		while ((ch = fgetc(f1)) != EOF) {
			if(ch > 64 && ch < 91) {
				ch -= key;
				if(ch < 65) ch += 26;
			}
			else if (ch > 96 && ch < 123) {
				ch -= key;
				if (ch < 97) ch += 26;
				
			}
			fputc(ch, f2);
		}
		fprintf(f2, "\r\n");
		fclose(f1);
	}
	fclose(f2);
	return 0;
}
