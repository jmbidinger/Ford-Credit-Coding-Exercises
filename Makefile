CC = gcc

CFLAGS = -Wall -g

all: mustangBronco manhattanDistance
mustangBronco: mustangBronco.c
	$(CC) $(CFLAGS) -o mustangBronco mustangBronco.c
	
manhattanDistance: manhattanDistance.c
	$(CC) $(CFLAGS) -o manhattanDistance manhattanDistance.c

clean:
	rm mustangBronco manhattanDistance