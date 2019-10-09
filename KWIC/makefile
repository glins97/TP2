CFLAGS = -std=c++17 -O
CC = g++

out: main
	$(CC) $(CFLAGS) -o out main.o alphabetizer.o kwic.o shift.o output.o input.o
	./out

main: kwic main.cpp
	$(CC) $(CFLAGS) -c main.cpp

kwic: kwic.cpp shift alphabetizer input output 
	$(CC) $(CFLAGS) -c kwic.cpp

alphabetizer: alphabetizer.cpp
	$(CC) $(CFLAGS) -c alphabetizer.cpp

shift: shift.cpp
	$(CC) $(CFLAGS) -c shift.cpp

output: output.cpp
	$(CC) $(CFLAGS) -c output.cpp

input: input.cpp
	$(CC) $(CFLAGS) -c input.cpp

clean:
	rm -f out *.o 