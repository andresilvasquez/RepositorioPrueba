#include <iostream>
#include <cmath>

typedef double REAL;

REAL sumup(int N);
REAL sumdown(int N);

int main(void)
{
  std::cout.precision(16); std::cout.setf(std::ios::scientific);
  
  for (int NMAX = 1; NMAX <= 10000; NMAX = NMAX + 100) {
    std::cout << NMAX
              << "\t" << sumup(NMAX)
              << "\t" << sumdown(NMAX)
              << "\t" << sumup(NMAX) - sumdown(NMAX)
              << std::endl;
  }
  return 0;
}

REAL sumup(int N)
{
    REAL term = 0, suma = 0;
    for (int i = 1; i <= N; ++i) {
        term = 1.0 / i;
        suma += term;
    }
    return suma;
}

REAL sumdown(int N)
{
    REAL term = 0, suma = 1/N;
    for (int i = 1; i < N; ++i) {
        term = 1.0 /(N-i);
        suma += term;
    }
    return suma;
}