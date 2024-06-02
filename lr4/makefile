TARGETS=*.c
CC=gcc

crypt: crypt.c
	cat input.txt
	$(CC) crypt.c aes128.c aes128.h -o crypt
	./crypt
	cat output.txt
	@echo
	
decrypt: decrypt.c
	cat output.txt
	$(CC) decrypt.c aes128.c aes128.h -o decrypt
	./decrypt
	cat input_dec.txt
	@echo
	
clean:
	-rm -rf crypt decrypt
