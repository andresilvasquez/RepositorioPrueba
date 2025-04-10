#include <iostream>
#include <cstdlib>

//typedef float REAL;
typedef double REAL;

int main(int argc, char **argv)
{
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);

    if (argc < 2) {
        std::cerr << "Se necesita un argumento (N)" << std::endl;
        return 1;
    }

    int N = std::atoi(argv[1]);
    REAL under = 1.0, over = 1.0;

    for (int ii = 0; ii < N; ++ii) {
        under /= 2;
        over *= 2;
        std::cout << ii << "\t" << under << "\t" << over << std::endl;
    }

    return 0;
}
