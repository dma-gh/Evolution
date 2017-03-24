CC=gcc
CFLAGS=-Wall -g
MATH = -lm 
rand : rand.o functions.o
	$(CC) $(CFLAGS) rand.o functions.o -o rand 

functions.o : functions.c 
	$(CC) $(CFLAGS) -c functions.c $(MATH)
rand.o : rand.c 
	$(CC) $(CFLAGS) -c rand.c  $(MATH)

.PHONY: clean
clean:
	rm -f rand.o functions.o 