#ifndef SIMULATION_HPP
#define SIMULATION_HPP
#include "PriorityQueue.hpp"
#include "FifoQueue.hpp"
#include <complex>
class Simulation {
    private:
        PriorityQueue pq;
        FifoQueue fq;
        int n;
        float lambda;
        float mu;
        int M;

        int availableServers;
        float prevArrivalTime;
        float totalSimTime;
        float totalIdleTime;
        int numWaited;
        float totalWaitTime;
        float totalServiceTime;  
        float totalCustomerTime;

        float getRandomInterval(float avg);
        void insertArrival();
        void processNextEvent();
        void processStatistics(Customer* event);
    public:
        Simulation();
        Simulation(float lambda, float mu, int M);
        void run(int n);
};
#endif