input_sort = insertion_sort

CC = gcc

PROGRAMS = tester.c testing.c $(input_sort).c

all: tester

tester:  $(PROGRAMS)
	$(CC) $(PROGRAMS) -o tester
	
clean:
	rm -rf *.o tester
