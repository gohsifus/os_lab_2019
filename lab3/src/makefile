CC=gcc
CFLAGS=-I.
STDFLAGS =-std=c99

tsk5 :
	$(CC) -o task5 task5.c $(CFLAGS)

all : utils.o find_min_max.o utils.h find_min_max.h
	$(CC) $(STDFLAGS) -o sequential_min_max find_min_max.o utils.o sequential_min_max.c $(CFLAGS)
	$(CC) $(STDFLAGS) -o parallel_min_max utils.o find_min_max.o parallel_min_max.c $(CFLAGS)
	$(CC) $(STDFLAGS) -o utils.o -c utils.c $(CFLAGS)
	$(CC) $(STDFLAGS) -o find_min_max.o -c find_min_max.c $(CFLAGS)

sequential_min_max : utils.o find_min_max.o utils.h find_min_max.h
	$(CC) $(STDFLAGS) -o sequential_min_max find_min_max.o utils.o sequential_min_max.c $(CFLAGS)

parallel_min_max : utils.o find_min_max.o utils.h find_min_max.h
	$(CC) $(STDFLAGS) -o parallel_min_max utils.o find_min_max.o parallel_min_max.c $(CFLAGS)

utils.o : utils.h
	$(CC) $(STDFLAGS) -o utils.o -c utils.c $(CFLAGS)

find_min_max.o : utils.h find_min_max.h
	$(CC) $(STDFLAGS) -o find_min_max.o -c find_min_max.c $(CFLAGS)

clean :
	rm utils.o find_min_max.o sequential_min_max parallel_min_max
