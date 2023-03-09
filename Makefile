CC = gcc
CFLAGS = -Wall -Wextra -g

all: driver

driver: driver.o kernel.o
	$(CC) $(CFLAGS) -o driver driver.o kernel.o

driver.o: driver.c kernel.h
	$(CC) $(CFLAGS) -c driver.c

kernel.o: kernel.c kernel.h
	$(CC) $(CFLAGS) -c kernel.c

clean:
	rm -f driver driver.o kernel.o