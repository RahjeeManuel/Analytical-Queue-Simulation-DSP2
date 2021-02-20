#ifndef ANALYTICALMODEL_HPP
#define ANALYTICALMODEL_HPP
class AnalyticalModel {
    private:
        int n;          //number of arrivals to simulate (1000-5000)
        float lambda;   //average arrivals in a time period
        float mu;       //average number served in time period
        int M;          //number of service channels (1-10)

        float factorial(float num);
    public:
        AnalyticalModel();
        AnalyticalModel(int n, float lambda, float mu, int M);

        void setN(int n);
        void setLambda(float lambda);
        void setMu(float mu);
        void setM(int M);

        int getN();
        float getLambda();
        float getMu();
        int getM();

        float getPo();       //percent idle time
        float getL();        //average number of people in the system
        float getW();        //average time a customer spends in the system
        float getLq();       //average number of customers in the queue
        float getWq();       //average time a customer spends waiting in the queue
        float getRho();      //utilization factor
};
#endif