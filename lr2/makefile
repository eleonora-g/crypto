TARGETS=*.c
CC=gcc

first: first.c
	$(CC) first.c -o first
	./first
	
second: second.c
	$(CC) second.c -lm -o second
	./second
	
third: third.c
	$(CC) third.c -o third
	$(CC) second.c -lm -o second
	./third
	./second

clean:
	-rm -rf first second third
