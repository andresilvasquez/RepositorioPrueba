#include <random>
#include <iostream>
#include <cstdlib>

double compute_pi(int seed, long nsamples);

int main(int argc, char **argv) 
{
  const int SEED = std::atoi(argv[1]);
  const long NSAMPLES = std::atol(argv[2]);
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  double mypi = compute_pi(SEED, NSAMPLES);
  std::cout << mypi << "\n"; 
    
  return 0;
}

double compute_pi(int seed, long nsamples) 
{
  std::mt19937 gen(seed);
  std::uniform_real_distribution<double> dis(-0.5,0.5);
  long ey = 0;

  for (int i = 0; i < nsamples; ++i){
    double x = dis(gen);
    double y = dis(gen);

    if (x*x + y*y <= 1.0/4.0){
        ey++;
    }
  }
  return 4.0*ey/nsamples;
}