CFLAGS = -O
CC = g++

out: main.o io.o
	$(CC) $(CFLAGS) -o out main.o io.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

io.o: io.cpp
	$(CC) $(CFLAGS) -c io.cpp

clean:
	rm -f out *.o 