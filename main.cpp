#include "Customer.hpp"
#include "PriorityQueue.hpp"
#include <iostream>
int main() {
    Customer* a = new Customer();
    a->setPqTime(1);
    Customer* b = new Customer();
    b->setPqTime(3);
    Customer* c = new Customer();
    c->setPqTime(4);
    Customer* d = new Customer();
    d->setPqTime(0.7);
    Customer* e = new Customer();
    e->setPqTime(5);
    Customer* f = new Customer();
    f->setPqTime(3);
    
    PriorityQueue pq;
    pq.insert(a);
    pq.insert(b);
    pq.insert(c);
    pq.insert(d);
    pq.insert(e);
    pq.insert(f);

    std::cout << pq.extractNext()->getPqTime() << std::endl;
    std::cout << pq.extractNext()->getPqTime() << std::endl;
    std::cout << pq.extractNext()->getPqTime() << std::endl;
    std::cout << pq.extractNext()->getPqTime() << std::endl;
    std::cout << pq.extractNext()->getPqTime() << std::endl;
    std::cout << pq.extractNext()->getPqTime() << std::endl;

    std::cout << pq.extractNext() << std::endl;
    return 0;
}