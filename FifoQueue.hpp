#ifndef FIFOQUEUE_HPP
#define FIFOQUEUE_HPP
#include "Customer.hpp"
class FifoQueue {
    private:
        Customer* head;
        Customer* tail;
    public:
        FifoQueue();

        void addCustomer(Customer* customer);

        Customer* getNextCustomer();
};
#endif