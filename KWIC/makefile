CFLAGS = -std=c++17 -O
CC = g++

out: main
	$(CC) $(CFLAGS) -o out main.o alphabetizer.o kwic.o shift.o output.o input.o
	./out

main: kwic main.cpp
	$(CC) $(CFLAGS) -c main.cpp

kwic: kwic/kwic.cpp shift alphabetizer input output 
	$(CC) $(CFLAGS) -c kwic/kwic.cpp

alphabetizer: alphabetizer/alphabetizer.cpp
	$(CC) $(CFLAGS) -c alphabetizer/alphabetizer.cpp

shift: shifter/shift.cpp
	$(CC) $(CFLAGS) -c shifter/shift.cpp

output: output/output.cpp
	$(CC) $(CFLAGS) -c output/output.cpp

input: input/input.cpp
	$(CC) $(CFLAGS) -c input/input.cpp

clean:
	rm -f out *.o 