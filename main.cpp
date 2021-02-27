#include "AnalyticalModel.hpp"
#include "Simulation.hpp"
#include <iostream>
using namespace std;
int main() {
    int n;
    float lambda;
    float mu;
    int M;

    //Asks for inputs
    do {
        std::cout << "Enter n (1000-5000):";
        std::cin >> n;
    } while (!(n >= 1000 && n <= 5000));
    std::cout << "Enter lambda:";
    std::cin >> lambda;
    std::cout << "Enter mu:";
    std::cin >> mu;
    do {
        std::cout << "Enter M (1-10):";
        std::cin >> M;
    } while (!(M >= 1 && M <= 10));

    //Display analytical model results
    AnalyticalModel am(lambda, mu, M);
    cout << "\nAnalytical Model:" << endl;
    cout << "Po: " << am.getPo() << endl;
    cout << "W: " << am.getW() << endl;
    cout << "Wq: " << am.getWq() << endl;
    cout << "Rho: " << am.getRho() << endl;

    //Run simulation and display results
    Simulation s(lambda, mu, M);
    s.run(n);

    return 0;
}