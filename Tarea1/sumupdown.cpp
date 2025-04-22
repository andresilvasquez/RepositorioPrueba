#include <iostream>
#include <cmath>

typedef float REAL;

REAL sumup(int N);
REAL sumdown(int N);

int main(void)
{
  std::cout.precision(16); std::cout.setf(std::ios::scientific);
  
  for (int NMAX = 1; NMAX <= 1000000; NMAX++) {
    REAL up = sumup(NMAX);
    REAL down = sumdown(NMAX);
    REAL diff = std::abs(1.0 - up / down);

    std::cout << NMAX
              << "\t" << up
              << "\t" << down
              << "\t" << diff
              << std::endl;
  }
  return 0;
}

REAL sumup(int N)
{
    REAL suma = 0.0;
    for (int i = 1; i <= N; ++i) {
        suma += 1.0 / i;
    }
    return suma;
}

REAL sumdown(int N)
{
    REAL suma = 0.0;
    for (int i = N; i >= 1; --i) {
        suma += 1.0 / i;
    }
    return suma;
}