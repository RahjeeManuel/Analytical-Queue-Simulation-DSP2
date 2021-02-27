#builds dsp2.exe
all: dsp2.exe

dsp2.exe: main.o Simulation.o AnalyticalModel.o PriorityQueue.o FifoQueue.o Customer.o
	g++ -o dsp2.exe main.o Simulation.o AnalyticalModel.o PriorityQueue.o FifoQueue.o Customer.o

main.o: main.cpp
	g++ -c main.cpp

Simulation.o: Simulation.hpp Simulation.cpp
	g++ -c Simulation.cpp

AnalyticalModel.o: AnalyticalModel.hpp AnalyticalModel.cpp
	g++ -c AnalyticalModel.cpp

PriorityQueue.o: PriorityQueue.hpp PriorityQueue.cpp
	g++ -c PriorityQueue.cpp

FifoQueue.o: FifoQueue.hpp FifoQueue.cpp
	g++ -c FifoQueue.cpp

Customer.o: Customer.hpp Customer.cpp
	g++ -c Customer.cpp

clean:
	rm *.o dsp2.exe