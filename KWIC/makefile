CFLAGS = -O
CC = g++

out: main
	$(CC) $(CFLAGS) -o out main.o alphabetizer.o shift.o output.o input.o

main: input
	$(CC) $(CFLAGS) -c main.cpp

alphabetizer: alphabetizer.cpp
	$(CC) $(CFLAGS) -c alphabetizer.cpp

shift: shift.cpp
	$(CC) $(CFLAGS) -c shift.cpp

output: output.cpp
	$(CC) $(CFLAGS) -c output.cpp

input:
	$(CC) $(CFLAGS) -c input.cpp

clean:
	rm -f out *.o 