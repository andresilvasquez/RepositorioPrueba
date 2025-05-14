#include <iostream>
#include <cstdlib>
#include <cmath>

// Declaraciones de funciones
int foo(int a, int b);
int bar(int a, int b);
double baz(double x);
void print_array(const double data[], const int & size);

int main (int argc, char **argv)
{
  int ii = 0;  // Inicialización directa
  int jj = -1; // Inicialización directa

  foo(ii, jj); // Ahora maneja división por cero internamente
  foo(jj, ii); 

  std::cout << "baz(25.9) = " << baz(25.9) << "\n"; // Ahora se imprime el resultado

  // Declaración e inicialización de arreglos
  const int NX = 2, NY = 3, NZ = 4;

  double data[NX + NY + NZ] = {0}; //Arreglo que garantiza que x,y,z estén
  double *z = &data[0];            //memoria contigua
  double *y = &data[NZ];           //primero z luego y luego x
  double *x = &data[NZ + NY];

  // Imprimir arreglos inicialmente
  print_array(x, NX);
  print_array(y, NY);
  print_array(z, NZ);
  std::cout << std::endl;

  // se cambió jj por ii para evitar x[-1], direccion invalida
  for (ii = 0; ii < NX; ++ii) {
    x[ii] = ii;
  }

  // Imprimir arreglos con tamaños correctos
  print_array(x, NX); //este sí tuve que cambiarlo pues con NZ se salía del arreglo
  print_array(y, NY); //mismo llamado
  print_array(z, NZ + NY); //mismo llamado
  std::cout << std::endl;

  // Escritura segura en x y y
  for (jj = 0; jj < NY; ++jj) { //lo separé en 2 for uno para y que va hasta NY
    y[jj] = jj;
  }

  for (ii = 0; ii < NX; ++ii) { //y otro para x que va hasta NX
    x[ii] = ii;  
  }

  print_array(x - NY, NY); //mismo llamado
  print_array(y - NZ, NZ); //mismo llamado
  print_array(z + NZ + NY, NX); //mismo llamado
  std::cout << std::endl;

  return EXIT_SUCCESS;
}

// Corrección: protección contra división por cero
int foo(int a, int b)
{
  if (a == 0 || b == 0) {
    std::cerr << "Error: división por cero en foo()\n";
    return 0;
  }
  return a / b + b / bar(a, b) + b / a;
}

// Sin cambios
int bar(int a, int b)
{
  unsigned int c = a;
  return c + a - b;
}

// Corrección: comparación, return válido, punto y coma
double baz(double x)
{
  if (x == 0) return 0.0;        // Comparación correcta y return double
  double v = 1 - (x + 1);        // No se usa, pero sintácticamente válido
  return std::sqrt(x);          // Punto y coma añadido
}

// Sin cambios, esta función está bien escrita
void print_array(const double data[], const int & size)
{
  std::cout << std::endl;
  for (int ii = 0; ii < size; ++ii) {
    std::cout << data[ii] << "  ";
  }
}
