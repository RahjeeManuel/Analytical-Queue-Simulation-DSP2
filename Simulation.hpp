#ifndef SIMULATION_HPP
#define SIMULATION_HPP
#include "PriorityQueue.hpp"
#include "FifoQueue.hpp"
#include <complex>
class Simulation {
    private:
        PriorityQueue pq;
        FifoQueue fq;
        
        int n;              //number of arrivals to simulate
        float lambda;       //average arrivals in a time period
        float mu;           //average number served in time period
        int M;              //number of service channels (1-10)

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
        Simulation(float lambda, float mu, int M);
        void run(int n);
};
#endif