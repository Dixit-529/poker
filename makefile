CC = g++
CFLAGS = -std=c++11 -Wall

all: poker

poker: card.o hand.o pocker.o
	$(CC) $(CFLAGS) card.o hand.o pocker.o -o poker

card.o: card.cpp card.h
	$(CC) $(CFLAGS) -c card.cpp

hand.o: hand.cpp hand.h card.h
	$(CC) $(CFLAGS) -c hand.cpp

pocker.o: pocker.cpp hand.h
	$(CC) $(CFLAGS) -c pocker.cpp

clean:
	rm -rf *.o poker

