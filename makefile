a.out: main.o calculate.o
	g++ main.o calculate.o
main.o: main.cpp calculate.o
	g++ -c main.cpp
calculate.o: calculate.cpp calculate.h
	g++ -c calculate.cpp
clean:
	rm -f a.out *.o
