CC=gcc
CFLAGS=-Wall -g
MATH = -lm 
rand : rand.c
	$(CC) $(CFLAGS) rand.c -o rand $(MATH)
