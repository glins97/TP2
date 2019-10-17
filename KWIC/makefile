CFLAGS = -std=c++17 -O
CC = g++

# -----------------------------------------
# 					MAIN
# -----------------------------------------
out: main.o factory.o kwic.o inputs.o outputs.o alphabetizers.o shifts.o
	$(CC) $(CFLAGS) -o out *.o
	./out

kwic.o: kwic/kwic.cpp
	$(CC) $(CFLAGS) -c kwic/kwic.cpp 

factory.o: factory/factory.cpp
	$(CC) $(CFLAGS) -c factory/factory.cpp 

main.o: kwic/kwic.cpp main.cpp
	$(CC) $(CFLAGS) -c main.cpp
# -----------------------------------------


# -----------------------------------------
# 					OUTPUT
# -----------------------------------------
outputs.o: baseoutput.o printoutput.o textoutput.o xmloutput.o csvoutput.o htmloutput.o

printoutput.o: baseoutput.o output/printoutput.cpp
	$(CC) $(CFLAGS) -c output/printoutput.cpp

xmloutput.o: baseoutput.o output/xmloutput.cpp
	$(CC) $(CFLAGS) -c output/xmloutput.cpp

csvoutput.o: baseoutput.o output/csvoutput.cpp
	$(CC) $(CFLAGS) -c output/csvoutput.cpp

htmloutput.o: baseoutput.o output/htmloutput.cpp
	$(CC) $(CFLAGS) -c output/htmloutput.cpp

textoutput.o: baseoutput.o output/textoutput.cpp
	$(CC) $(CFLAGS) -c output/textoutput.cpp

baseoutput.o: output/baseoutput.cpp
	$(CC) $(CFLAGS) -c output/baseoutput.cpp
# -----------------------------------------



# -----------------------------------------
# 				ALPHABETIZER
# -----------------------------------------
alphabetizers.o: basealphabetizer.o crappyalphabetizer.o quickalphabetizer.o

crappyalphabetizer.o: basealphabetizer.o alphabetizer/crappyalphabetizer.cpp
	$(CC) $(CFLAGS) -c alphabetizer/crappyalphabetizer.cpp

quickalphabetizer.o: basealphabetizer.o alphabetizer/quickalphabetizer.cpp
	$(CC) $(CFLAGS) -c alphabetizer/quickalphabetizer.cpp

basealphabetizer.o: alphabetizer/basealphabetizer.cpp
	$(CC) $(CFLAGS) -c alphabetizer/basealphabetizer.cpp
# -----------------------------------------



# -----------------------------------------
# 					SHIFTS
# -----------------------------------------
shifts.o: baseshift.o nswshift.o swshift.o

nswshift.o: baseshift.o shifter/nswshift.cpp
	$(CC) $(CFLAGS) -c shifter/nswshift.cpp

swshift.o: baseshift.o shifter/swshift.cpp
	$(CC) $(CFLAGS) -c shifter/swshift.cpp

baseshift.o: shifter/baseshift.cpp
	$(CC) $(CFLAGS) -c shifter/baseshift.cpp
# -----------------------------------------



# -----------------------------------------
# 					INPUTS
# -----------------------------------------
inputs.o: baseinput.o textinput.o csvinput.o xmlinput.o sqlinput.o dblpinput.o

textinput.o: baseinput.o input/textinput.cpp 
	$(CC) $(CFLAGS) -c input/textinput.cpp

csvinput.o: baseinput.o input/csvinput.cpp 
	$(CC) $(CFLAGS) -c input/csvinput.cpp

xmlinput.o: baseinput.o input/xmlinput.cpp 
	$(CC) $(CFLAGS) -c input/xmlinput.cpp

dblpinput.o: baseinput.o input/dblpinput.cpp 
	$(CC) $(CFLAGS) -c input/dblpinput.cpp

sqlinput.o: baseinput.o input/sqlinput.cpp 
	$(CC) $(CFLAGS) -c input/sqlinput.cpp

baseinput.o: input/baseinput.cpp
	$(CC) $(CFLAGS) -c input/baseinput.cpp
# -----------------------------------------

clean:
	rm -f out *.o 