numbers: numbers.c
	gcc -Wall -pedantic –std=c1x numbers.c -o numbers
clean :
	rm -f *.o *.c 