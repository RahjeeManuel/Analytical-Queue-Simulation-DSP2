#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP
class Customer {
    private:
        float arrivalTime;
        float startOfServiceTime;
        float departureTime;
        float pqTime;
        Customer* nextCustomer;
    private:
        Customer();
        
        void setArrivalTime(float arrivalTime);
        void setStartOfServiceTime(float startOfServiceTime);
        void setDepartureTime(float departureTime);
        void setPqTime(float pqTime);
        void setNextCustomer(Customer* nextCustomer);

        float getArrivalTime();
        float getStartOfServiceTime();
        float getDepartureTime();
        float getPqTime();
        Customer* getNextCustomer();
};
#endif