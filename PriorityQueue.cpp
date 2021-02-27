#include "PriorityQueue.hpp"
int PriorityQueue::parent(int i) {
    return (i - 1) / 2;
}
int PriorityQueue::left(int i) {
    return 2 * i + 1;
}
int PriorityQueue::right(int i) {
    return 2 * i + 2;
}

void PriorityQueue::minHeap(int i) {
    int l = left(i); 
    int r = right(i); 
    int min = i; 
    if (l < currentSize && pq[l]->getPqTime() < pq[i]->getPqTime()) {
        min = l;         
    }
    if (r < currentSize && pq[r]->getPqTime() < pq[min]->getPqTime()) {
        min = r; 
    }
    if (min != i) { 
        swap(&pq[i], &pq[min]); 
        minHeap(min); 
    }     
}
void PriorityQueue::swap(Customer** a, Customer** b) {
    Customer* c = *a; 
    *a = *b; 
    *b = c; 
}

PriorityQueue::PriorityQueue() {
    this->maxSize = 200;
    this->currentSize = 0;
    this->pq = new Customer*[maxSize];
}
PriorityQueue::PriorityQueue(int maxSize) {
    this->maxSize = maxSize;
    this->currentSize = 0;
    this->pq = new Customer*[maxSize];    
}

bool PriorityQueue::isEmpty() {
    if (currentSize == 0) {
        return true;
    } else {
        return false;
    }
}
int PriorityQueue::getSize() {
    return currentSize;
}
void PriorityQueue::insert(Customer* customer) {
    if (currentSize == maxSize) {
        return;
    }
    currentSize++;
    int i = currentSize - 1;
    pq[i] = customer;
    while (i != 0 && pq[parent(i)]->getPqTime() > pq[i]->getPqTime()) {
        swap(&pq[i], &pq[parent(i)]);
        i = parent(i);
    }
}
Customer* PriorityQueue::getNext() {
    if (currentSize <= 0) {
        return nullptr;         
    } else {
        return pq[0];
    }
}
Customer* PriorityQueue::extractNext() {
    if (currentSize <= 0) {
        return nullptr;         
    }
    if (currentSize == 1) { 
        currentSize--; 
        return pq[0]; 
    } 
    Customer* root = pq[0]; 
    pq[0] = pq[currentSize - 1]; 
    currentSize--; 
    minHeap(0); 
    return root;     
}