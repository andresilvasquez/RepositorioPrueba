#include <vector>
#include <iostream>

void print_v0(const std::vector <double> & mydata); //const quita permiso de reescritura
void print_v1(const std::vector <double> & mydata);

int main(void) {
    std::vector<double> data= {0.1, 0.5, -0.6};

    print_v0(data);
    print_v1(data);

    return 0;
}

void print_v0(const std::vector <double> & mydata) {
    for(int i =0; i<mydata.size(); i++) {
        std::cout << mydata[i] << "  ";
    }
    std::cout << "\n";
}

void print_v1(const std::vector <double> & mydata) {
    for(auto & x : mydata) { //con & x es una referencia no una copia
        std::cout << x << "  ";
    }
    std::cout << "\n";
}


//