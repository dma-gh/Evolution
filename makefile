CC=gcc
CFLAGS=-Wall -g

rand : rand.c
	$(CC) $(CFLAGS) rand.c -o rand 
