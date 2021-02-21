#include "FifoQueue.hpp"
FifoQueue::FifoQueue() {
    this->head = nullptr;
    this->tail = nullptr;
}

void FifoQueue::addCustomer(Customer* customer) {
    tail->setNextCustomer(customer);
    tail = customer;
}

Customer* FifoQueue::getNextCustomer() {
    Customer* next = head;
    head = head->getNextCustomer();
    next->setNextCustomer(nullptr);
    return next;
}