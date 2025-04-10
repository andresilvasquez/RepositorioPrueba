#include <iostream>
#include <cstdlib>

typedef float REAL;

int main()
{   
    std::cout.precision(20);
    std::cout.setf(std::ios::scientific);

    REAL eps = 1.0, one = 1.0;

    while (1.0 + eps > 1.0) {
        eps /= 2;
        std::cout << 1.0 + eps << "\t" << eps << std::endl;
    }

    std::cout << "La precision es: " << eps << std::endl;

    return 0;
}
