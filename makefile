a.out: main.o calculate.o Customer.o CustomerDatabase.o
	g++ main.o calculate.o Customer.o CustomerDatabase.o
main.o: main.cpp
	g++ -c main.cpp
calculate.o: calculate.cpp calculate.h
	g++ -c calculate.cpp
Customer.o: Customer.cpp Customer.h
	g++ -c Customer.cpp
CustomerDatabase.o: CustomerDatabase.cpp CustomerDatabase.h
	g++ -c CustomerDatabase.cpp
clean:
	rm *.o a.out
