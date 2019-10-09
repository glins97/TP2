CFLAGS = -std=c++17 -O
CC = g++

# -----------------------------------------
# 					MAIN
# -----------------------------------------
out: main.o
	$(CC) $(CFLAGS) -o out *.o
	./out

main.o: kwic.o main.cpp
	$(CC) $(CFLAGS) -c main.cpp

kwic.o: kwic/kwic.cpp	
	$(CC) $(CFLAGS) -c kwic/kwic.cpp
# -----------------------------------------



# -----------------------------------------
# 					OUTPUT
# -----------------------------------------
outputs.o: baseoutput.o printoutput.o

printoutput.o: baseoutput.o output/printoutput.cpp
	$(CC) $(CFLAGS) -c output/printoutput.cpp

baseoutput.o: output/baseoutput.cpp
	$(CC) $(CFLAGS) -c output/baseoutput.cpp
# -----------------------------------------



# -----------------------------------------
# 				ALPHABETIZER
# -----------------------------------------
alphabetizers.o: basealphabetizer.o nswalphabetizer.o swalphabetizer.o

nswalphabetizer.o: basealphabetizer.o alphabetizer/nswalphabetizer.cpp
	$(CC) $(CFLAGS) -c alphabetizer/nswalphabetizer.cpp

swalphabetizer.o: basealphabetizer.o alphabetizer/swalphabetizer.cpp
	$(CC) $(CFLAGS) -c alphabetizer/swalphabetizer.cpp

basealphabetizer.o: alphabetizer/basealphabetizer.cpp
	$(CC) $(CFLAGS) -c alphabetizer/basealphabetizer.cpp
# -----------------------------------------



# -----------------------------------------
# 					SHIFTS
# -----------------------------------------
shifts.o: baseshift.o rightshift.o leftshift.o

rightshift.o: baseshift.o shifter/rightshift.cpp
	$(CC) $(CFLAGS) -c shifter/rightshift.cpp

leftshift.o: baseshift.o shifter/leftshift.cpp
	$(CC) $(CFLAGS) -c shifter/leftshift.cpp

baseshift.o: shifter/baseshift.cpp
	$(CC) $(CFLAGS) -c shifter/baseshift.cpp
# -----------------------------------------



# -----------------------------------------
# 					INPUTS
# -----------------------------------------
inputs.o: baseinput.o textinput.o csvinput.o

textinput.o: baseinput.o input/textinput.cpp 
	$(CC) $(CFLAGS) -c input/textinput.cpp

csvinput.o: baseinput.o input/csvinput.cpp 
	$(CC) $(CFLAGS) -c input/csvinput.cpp

baseinput.o: input/baseinput.cpp
	$(CC) $(CFLAGS) -c input/baseinput.cpp
# -----------------------------------------

clean:
	rm -f out *.o 