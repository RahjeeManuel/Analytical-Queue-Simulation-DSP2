#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP
#include "Customer.hpp"
class PriorityQueue {
    private:
        Customer** pq;
        int maxSize;
        int currentSize;

        int parent(int i);          //returns parent index
        int left(int i);            //returns left index
        int right(int i);           //return right index

        void minHeap(int i);        //min heaps the pq array
        void swap(Customer** a, Customer** b);
    public:
        PriorityQueue();
        ~PriorityQueue();

        bool isEmpty();
        int getSize();
        void insert(Customer* customer);
        Customer* getNext();        //returns root
        Customer* extractNext();    //returns root and removes it
};
#endif