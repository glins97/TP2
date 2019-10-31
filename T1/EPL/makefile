CFLAGS = -O
CC = g++

out: main.o
	$(CC) $(CFLAGS) -o out *.o
	./out

main.o: main.cpp printer.o addevaluator.o negevaluator.o evaluator.o literal.o add.o neg.o
	$(CC) $(CFLAGS) -c main.cpp  

printer.o: visitor.o visitor/printer.cpp
	$(CC) $(CFLAGS) -c visitor/printer.cpp

addevaluator.o: evaluator.o visitor/addevaluator.cpp
	$(CC) $(CFLAGS) -c visitor/addevaluator.cpp

negevaluator.o: evaluator.o visitor/negevaluator.cpp
	$(CC) $(CFLAGS) -c visitor/negevaluator.cpp

evaluator.o: visitor.o visitor/evaluator.cpp
	$(CC) $(CFLAGS) -c visitor/evaluator.cpp

visitor.o: visitor/expr.cpp
	$(CC) $(CFLAGS) -c visitor/expr.cpp

neg.o: expr.o expr/neg.cpp
	$(CC) $(CFLAGS) -c expr/neg.cpp

add.o: expr.o expr/add.cpp
	$(CC) $(CFLAGS) -c expr/add.cpp

literal.o: expr.o expr/literal.cpp
	$(CC) $(CFLAGS) -c expr/literal.cpp

expr.o: expr/base.cpp
	$(CC) $(CFLAGS) -c expr/base.cpp

clean:
	rm -f out *.o 