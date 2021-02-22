#include "FifoQueue.hpp"
FifoQueue::FifoQueue() {
    this->head = nullptr;
    this->tail = nullptr;
}

void FifoQueue::addCustomer(Customer* customer) {
    if (head == nullptr) {
        head = customer;
        tail = customer;
    } else {
        tail->setNextCustomer(customer);
        tail = customer;
    }
}

Customer* FifoQueue::getNextCustomer() {
    if (head == nullptr) {
        return nullptr;
    } else {
        Customer* next = head;
        head = head->getNextCustomer();
        next->setNextCustomer(nullptr);
        return next;
    }
}