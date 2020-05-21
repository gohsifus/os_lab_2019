CC=gcc
CFLAGS=-I.
STDFLAGS =-std=c99
PTHREAD = -pthread

all : 
	
	$(CC) $(STDFLAGS) -o task4 process_memory.c $(CFLAGS)
	$(CC) $(STDFLAGS) -o parallel_min_max ./task1/parallel_min_max.c $(CFLAGS)
	$(CC) $(PTHREAD) $(STDFLAGS) parallel_sum.c -o task5 
