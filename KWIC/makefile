CFLAGS = -O
CC = g++

out: main.o alphabetizer.o shift.o output.o input.o
	$(CC) $(CFLAGS) -o out main.o alphabetizer.o shift.o output.o input.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

alphabetizer.o: alphabetizer.cpp
	$(CC) $(CFLAGS) -c alphabetizer.cpp

shift.o: shift.cpp
	$(CC) $(CFLAGS) -c shift.cpp

output.o: output.cpp
	$(CC) $(CFLAGS) -c output.cpp

input.o: input.cpp
	$(CC) $(CFLAGS) -c input.cpp

clean:
	rm -f out *.o 