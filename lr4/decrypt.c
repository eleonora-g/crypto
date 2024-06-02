#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "aes128.h"
#define FILE_IN "output.txt"
#define FILE_OUT "input_dec.txt"
#define size(x) (sizeof(x)/sizeof(*x))

static FILE *f1, *f2;
static uint8_t key[16], len;
static uint8_t text[2][256];
static uint16_t text_len;
static char ch;
static unsigned char op;
static uint16_t i;

int main() {
    f1 = fopen(FILE_IN, "r");
    f2 = fopen(FILE_OUT, "w");
    for (i = 0; i < size(key); i++) key[i] = 0; 
    while (!(len = strlen((char*)key))) {
        printf("key: ");
        scanf("%s", key);
    }
    i = 2; 
    for (i = 0; i < size(text[0]); i++) text[0][i] = ' ';
    for (i = 0; (ch = fgetc(f1)) != EOF; i++) {
        if (i >= size(text[i])) break;
        text[0][i] = ch;
    }
    fclose(f1);
    if (i % BLOCKSIZE) i += BLOCKSIZE - (i % BLOCKSIZE);
    text_len = i;
    aesDecrypt(key, len, text[0], text[1], text_len);
    for (i = 0; i < text_len; i++) fputc(text[1][i], f2);
    fclose(f2);
    return 0;
}
