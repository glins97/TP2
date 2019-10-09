CFLAGS = -std=c++17 -O
CC = g++

out: main
	$(CC) $(CFLAGS) -o out *.o
	./out
	rm -f *.o 

main: kwic main.cpp
	$(CC) $(CFLAGS) -c main.cpp

kwic: kwic/kwic.cpp shift alphabetizer csvinput textinput input output 
	$(CC) $(CFLAGS) -c kwic/kwic.cpp

alphabetizer: alphabetizer/alphabetizer.cpp
	$(CC) $(CFLAGS) -c alphabetizer/alphabetizer.cpp

shift: shifter/shift.cpp
	$(CC) $(CFLAGS) -c shifter/shift.cpp

output: output/output.cpp
	$(CC) $(CFLAGS) -c output/output.cpp

textinput: input input/textinput.cpp 
	$(CC) $(CFLAGS) -c input/textinput.cpp

csvinput: input input/csvinput.cpp 
	$(CC) $(CFLAGS) -c input/csvinput.cpp

input: input/input.cpp
	$(CC) $(CFLAGS) -c input/input.cpp

clean:
	rm -f out *.o 