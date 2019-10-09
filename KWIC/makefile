CFLAGS = -std=c++17 -O
CC = g++

# -----------------------------------------
# 					MAIN
# -----------------------------------------
out: main
	$(CC) $(CFLAGS) -o out *.o
	./out
	rm -f *.o 

main: kwic main.cpp
	$(CC) $(CFLAGS) -c main.cpp

kwic: kwic/kwic.cpp alphabetizers inputs shifts outputs # USES ALL OTHERS
	$(CC) $(CFLAGS) -c kwic/kwic.cpp
# -----------------------------------------



# -----------------------------------------
# 					OUTPUT
# -----------------------------------------
outputs: baseoutput printoutput  

printoutput: output/printoutput.cpp
	$(CC) $(CFLAGS) -c output/printoutput.cpp

baseoutput: output/baseoutput.cpp
	$(CC) $(CFLAGS) -c output/baseoutput.cpp
# -----------------------------------------



# -----------------------------------------
# 				ALPHABETIZER
# -----------------------------------------
alphabetizers: basealphabetizer nswalphabetizer swalphabetizer

nswalphabetizer: basealphabetizer alphabetizer/nswalphabetizer.cpp
	$(CC) $(CFLAGS) -c alphabetizer/nswalphabetizer.cpp

swalphabetizer: basealphabetizer alphabetizer/swalphabetizer.cpp
	$(CC) $(CFLAGS) -c alphabetizer/swalphabetizer.cpp

basealphabetizer: alphabetizer/basealphabetizer.cpp
	$(CC) $(CFLAGS) -c alphabetizer/basealphabetizer.cpp
# -----------------------------------------



# -----------------------------------------
# 					SHIFTS
# -----------------------------------------
shifts: baseshift rightshift leftshift

rightshift: baseshift shifter/rightshift.cpp
	$(CC) $(CFLAGS) -c shifter/rightshift.cpp

leftshift: baseshift shifter/leftshift.cpp
	$(CC) $(CFLAGS) -c shifter/leftshift.cpp

baseshift: shifter/baseshift.cpp
	$(CC) $(CFLAGS) -c shifter/baseshift.cpp
# -----------------------------------------



# -----------------------------------------
# 					INPUTS
# -----------------------------------------
inputs: baseinput textinput csvinput

textinput: baseinput input/textinput.cpp 
	$(CC) $(CFLAGS) -c input/textinput.cpp

csvinput: baseinput input/csvinput.cpp 
	$(CC) $(CFLAGS) -c input/csvinput.cpp

baseinput: input/baseinput.cpp
	$(CC) $(CFLAGS) -c input/baseinput.cpp
# -----------------------------------------

clean:
	rm -f out *.o 