CC=gcc
CFLAGS+=-Wall
LDFLAGS+=-lm

%.o : %.c
	$(CC) -c $^

main : main.o calculate.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY : clean

clean :
	$(RM) *.o main

