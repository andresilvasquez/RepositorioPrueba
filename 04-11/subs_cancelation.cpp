#include <iostream>
#include <cmath>

typedef float REAL;

REAL sum1(int k);
REAL sum2(int k);
REAL sum3(int k);

int main(void) {

    std::cout.precision(7);
    std::cout.setf(std::ios::scientific);

   for(int k = 1; k<= 1000; k++) {
    std::cout << k << "\t" << sum1(k) << "\t" << sum2(k) << "\t" << sum3(k) 
    << "\t" << (sum3(k) - sum1(k))/sum3(k) << "\t" << (sum3(k)-sum2(k))/sum3(k) << "\n";
   } 

    return 0;
}

REAL sum1(int k) 
{
    REAL suma = 0.0, term = 0.0;
    for(int ii = 1; ii <= 2*k; ii++) {
        term = std::pow(-1.0,ii)*(ii/(ii+1.0));
        suma += term;
    }

    return suma;
}

REAL sum2(int k) 
{
    REAL suma1 = 0.0, term1 = 0.0;
    for(int ii = 1; ii <= k; ii++) {
        term1 = (2.0*ii-1.0)/(2.0*ii);
        suma1 += term1;
    }

    REAL suma2 = 0.0, term2 = 0.0;
    for(int ii = 1; ii <= k; ii++) {
        term2= (2.0*ii)/(2.0*ii+1.0);
        suma2 += term2;
    }

    return - suma1 + suma2;
}

REAL sum3(int k) 
{
    REAL suma = 0.0, term = 0.0;
    for(int ii = 1; ii <= k; ii++) {
        term = 1.0/(2.0*ii*(2.0*ii+1.0));
        suma += term;
    }

    return suma;
}