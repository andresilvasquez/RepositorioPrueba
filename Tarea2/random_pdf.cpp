#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iomanip> 

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins);

int main(int argc, char **argv)
{
  const int SEED = std::atoi(argv[1]);
  const int NSAMPLES = std::atoi(argv[2]);
  const double MU = std::atof(argv[3]);
  const double SIGMA = std::atof(argv[4]);
  const double XMIN = std::atof(argv[5]);
  const double XMAX = std::atof(argv[6]);
  const int NBINS = std::atoi(argv[7]);

  compute_pdf(SEED, NSAMPLES, MU, SIGMA, XMIN, XMAX, NBINS);
}

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins)
{
  // random stuff
  std::mt19937 gen(seed);
  std::normal_distribution<double> dis{mu, sigma};
  std::vector<int> histogram(nbins, 0);
  std::vector<double> pdf(nbins);


  for(int n = 0; n < nsamples; ++n) {
    double r = dis(gen);
    if (r >= xmin && r < xmax) {
        int bin = (int)((r - xmin) / (xmax - xmin) * nbins);
        histogram[bin]++;
        }   
    }
  
  double bin_width = (xmax - xmin) / nbins;
  for (int i = 0; i < nbins; i++) {
    pdf[i] = (double)histogram[i] / (nsamples * bin_width);
    double x = xmin + (i + 0.5) * bin_width; 
    std::cout << std::fixed << std::setprecision(8) << x << " " << pdf[i] << std::endl;
    }

}