TARGETS=*.c
CC=gcc

first: first.c
	$(CC) first.c -o first
	cat input.txt
	./first
	cat output.txt
	@echo
	
second: second.c
	cat input.txt
	$(CC) second.c -o second
	./second
	cat output.txt
	@echo
	$(CC) second_dec.c -o second_dec
	./second_dec
	cat output_dec.txt
	@echo
	
third: third.c
	$(CC) third.c -o third
	cat input.txt
	./third
	cat output.txt
	@echo
	$(CC) third_dec.c -o third_dec
	cat output_dec.txt

clean:
	-rm -rf first second second_dec third third_dec
