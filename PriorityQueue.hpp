#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP
#include "Customer.hpp"
class PriorityQueue {
    private:
        Customer** pq;
        int maxSize;
        int currentSize;

        int parent(int i);
        int left(int i);
        int right(int i);

        void minHeap(int i);
        void swap(Customer** a, Customer** b);
    public:
        PriorityQueue();
        PriorityQueue(int maxSize);

        bool isEmpty();
        int getSize();
        void insert(Customer* customer);
        Customer* getNext();
        Customer* extractNext();
};
#endif