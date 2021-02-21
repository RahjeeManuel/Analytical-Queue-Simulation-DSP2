#include "Customer.hpp"
Customer::Customer() {
    this->arrivalTime = -1;
    this->startOfServiceTime = -1;
    this->departureTime = -1;
    this->pqTime = -1;
    this->nextCustomer = nullptr;
}

void Customer::setArrivalTime(float arrivalTime) {
    this->arrivalTime = arrivalTime;
}
void Customer::setStartOfServiceTime(float startOfServiceTime) {
    this->startOfServiceTime = startOfServiceTime;
}
void Customer::setDepartureTime(float departureTime) {
    this->departureTime = departureTime;
}
void Customer::setPqTime(float pqTime) {
    this->pqTime = pqTime;
}
void Customer::setNextCustomer(Customer* nextCustomer) {
    this->nextCustomer = nextCustomer;
}

float Customer::getArrivalTime() {
    return arrivalTime;
}
float Customer::getStartOfServiceTime() {
    return startOfServiceTime;
}
float Customer::getDepartureTime() {
    return departureTime;
}
float Customer::getPqTime() {
    return pqTime;
}
Customer* Customer::getNextCustomer() {
    return nextCustomer;
}