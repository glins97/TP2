CFLAGS = -O
CC = g++

out: main.o main.o manager.o expressions.o
	$(CC) $(CFLAGS) -o out *.o
	./out

main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp  

manager.o: manager/manager.cpp 
	$(CC) $(CFLAGS) -c manager/manager.cpp


# -----------------------------------------
# 				Expression
# -----------------------------------------
expressions.o: base.o add.o literal.o

literal.o: base.o expression/literal.cpp 
	$(CC) $(CFLAGS) -c expression/literal.cpp

add.o: base.o expression/add.cpp 
	$(CC) $(CFLAGS) -c expression/add.cpp

base.o: expression/base.cpp
	$(CC) $(CFLAGS) -c expression/base.cpp
# -----------------------------------------

clean:
	rm -f out *.o 