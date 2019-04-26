a.out: bankSimulation.o calculate.o Customer.o CustomerDatabase.o linked_list.o single_node.o
	g++ bankSimulation.o calculate.o Customer.o CustomerDatabase.o linked_list.o single_node.o
bankSimulation.o: bankSimulation.cpp
	g++ -c bankSimulation.cpp
linked_list.o: linked_list.cpp linked_list.h
	g++ -c linked_list.cpp
single_node.o: single_node.cpp single_node.h
	g++ -c single_node.cpp
calculate.o: calculate.cpp calculate.h
	g++ -c calculate.cpp
Customer.o: Customer.cpp Customer.h
	g++ -c Customer.cpp
CustomerDatabase.o: CustomerDatabase.cpp CustomerDatabase.h
	g++ -c CustomerDatabase.cpp
clean:
	rm *.o a.out
