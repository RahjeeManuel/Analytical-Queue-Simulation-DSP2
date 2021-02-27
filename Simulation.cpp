#include "Simulation.hpp"
#include <iostream>
using namespace std;
float Simulation::getRandomInterval(float avg) {
    float f = (float)rand()/RAND_MAX;
    return -1 * (1.0 / avg) * log(f);
}
void Simulation::insertArrival() {
    Customer* arrival = new Customer;
    if (prevArrivalTime > 0) {
        arrival->setArrivalTime(prevArrivalTime + getRandomInterval(lambda));   //insert arrival with previous known arrival time
    } else {
        arrival->setArrivalTime(getRandomInterval(lambda));     //insert first arrival
    }
    arrival->setPqTime(arrival->getArrivalTime());
    prevArrivalTime = arrival->getPqTime();
    pq.insert(arrival);
    n--;
}
void Simulation::processNextEvent() {
    Customer* event = pq.extractNext();
    if (event->getPqTime() == event->getArrivalTime()) {    //is an arrival
        if (availableServers > 0) {
            availableServers--;
            event->setStartOfServiceTime(event->getArrivalTime());
            event->setDepartureTime(event->getStartOfServiceTime() + getRandomInterval(mu));
            event->setPqTime(event->getDepartureTime());  
            pq.insert(event);
        } else {
            fq.addCustomer(event);
        }
    } else {    //is a departure
        availableServers++;
        Customer* nextInFifo = fq.getNextCustomer();
        if (nextInFifo != nullptr) {    //if a customer is waiting in the fifo queue then,
            nextInFifo->setStartOfServiceTime(event->getDepartureTime());
            nextInFifo->setDepartureTime(nextInFifo->getStartOfServiceTime() + getRandomInterval(mu));
            nextInFifo->setPqTime(nextInFifo->getDepartureTime());
            pq.insert(nextInFifo);
            availableServers--;
        }
        processStatistics(event);
    }
}
void Simulation::processStatistics(Customer* event) {
    //total simulation time
    totalSimTime = event->getDepartureTime();
    //idle time before the first arrival in the simulation
    if (totalIdleTime == 0) {
        totalIdleTime = event->getStartOfServiceTime();
    }
    //idle time
    if (availableServers == M) {
        Customer* next = pq.getNext();
        if (next != nullptr) {
            totalIdleTime = totalIdleTime + next->getArrivalTime() - event->getDepartureTime();   
        }
    }
    //wait time
    float waitTime = event->getStartOfServiceTime() - event->getArrivalTime();
    if (waitTime > 0) {
        numWaited++;
        totalWaitTime = totalWaitTime + waitTime;
    }
    //total service and customer system time
    totalServiceTime = totalServiceTime + event->getDepartureTime() - event->getStartOfServiceTime();
    totalCustomerTime = totalCustomerTime + event->getDepartureTime() - event->getArrivalTime();
    delete event;
}

Simulation::Simulation(float lambda, float mu, int M) {
    this->lambda = lambda;
    this->mu = mu;
    this->M = M;
}

void Simulation::run(int totalArrivals) {
    n = totalArrivals;
    availableServers = M;
    //reset variables
    prevArrivalTime = 0;
    totalSimTime = 0;
    totalIdleTime = 0;
    numWaited = 0;
    totalWaitTime = 0;
    totalServiceTime = 0; 
    totalCustomerTime = 0;
    //place first arrival
    insertArrival();
    //simulation loop
    while (pq.isEmpty() == false) {
        processNextEvent();
        if (n > 0 && pq.getSize() < M + 1) {
            insertArrival();
        }
    }
    //display results
    cout << "\nSimulation: "  << endl;
    cout << "Po: " << totalIdleTime / totalSimTime << endl;
    cout << "W: " << totalCustomerTime / (float)totalArrivals << endl;
    cout << "Wq: " << totalWaitTime / (float)totalArrivals << endl;
    cout << "Rho: " << totalServiceTime / (M * totalSimTime) << endl;
    cout << "Wait probability: " << (float)numWaited / totalArrivals << endl;
}