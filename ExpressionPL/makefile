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
expressions.o: base.o add.o literal.o neg.o mul.o pow.o

literal.o: base.o expression/literal.cpp 
	$(CC) $(CFLAGS) -c expression/literal.cpp

add.o: base.o expression/add.cpp 
	$(CC) $(CFLAGS) -c expression/add.cpp

neg.o: base.o expression/neg.cpp 
	$(CC) $(CFLAGS) -c expression/neg.cpp

mul.o: base.o expression/mul.cpp 
	$(CC) $(CFLAGS) -c expression/mul.cpp

pow.o: base.o expression/pow.cpp 
	$(CC) $(CFLAGS) -c expression/pow.cpp

base.o: expression/base.cpp
	$(CC) $(CFLAGS) -c expression/base.cpp
# -----------------------------------------

clean:
	rm -f out *.o 