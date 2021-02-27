#include "AnalyticalModel.hpp"
#include <math.h>
float AnalyticalModel::factorial(float num) {
    if(num > 1) {
        return num * factorial(num - 1);
    } else {
        return 1;
    }
}
AnalyticalModel::AnalyticalModel() {
    this->lambda = 2;
    this->mu = 3;
    this->M = 2;
}
AnalyticalModel::AnalyticalModel(float lambda, float mu, int M) {
    this->lambda = lambda;
    this->mu = mu;
    this->M = M;
}

void AnalyticalModel::setLambda(float lambda) {
    this->lambda = lambda;   
}
void AnalyticalModel::setMu(float mu) {
    this->mu = mu;    
}
void AnalyticalModel::setM(int M) {
    this->M = M;    
}

float AnalyticalModel::getLambda() {
    return lambda;    
}
float AnalyticalModel::getMu() {
    return mu;  
}
int AnalyticalModel::getM() {
    return M;   
}

float AnalyticalModel::getPo() {
    float sum = 0;
    for (int i = 0; i <= M-1; i++) {
        sum = sum + (1 / factorial(i)) * pow((lambda / mu), i);
    }
   return 1 / (sum + (1 / factorial(M)) * (pow(lambda/mu, M)) * ((M * mu) / (M * mu - lambda)));
}
float AnalyticalModel::getL() {
    return ((lambda * mu * pow((lambda / mu), M)) / (factorial(M - 1) * pow((M * mu - lambda), 2))) * getPo() + lambda / mu;    
}
float AnalyticalModel::getW() {
    return getL() / lambda;   
}
float AnalyticalModel::getLq() {
    return getL() - lambda / mu;    
}
float AnalyticalModel::getWq() {
    return getLq() / lambda;    
}
float AnalyticalModel::getRho() {
    return lambda / (M * mu);    
}