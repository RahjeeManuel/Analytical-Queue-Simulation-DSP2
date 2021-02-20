#include "AnalyticalModel.hpp"
#include <iostream>
int main() {
    AnalyticalModel am;
    std::cout << "n = " << am.getN() << std::endl;
    std::cout << "lambda = " << am.getLambda() << std::endl;
    std::cout << "mu = " << am.getMu() << std::endl;
    std::cout << "M = " << am.getM() << std::endl;
    std::cout << std::endl;
    std::cout << "Po = " << am.getPo() << std::endl;
    std::cout << "L = " << am.getL() << std::endl;
    std::cout << "W = " << am.getW() << std::endl;
    std::cout << "Lq = " << am.getLq() << std::endl;
    std::cout << "Wq = " << am.getWq() << std::endl;
    std::cout << "Rho = " << am.getRho() << std::endl;
    return 0;
}