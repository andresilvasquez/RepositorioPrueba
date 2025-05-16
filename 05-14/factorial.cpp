#include "factorial.h"

long factorial(long number)
{
    if(number == 0) return 1;
    if(number < 0) {
        std::cerr << "Negative nymbers not allowed returning -1";
        return -1;
    }
    return number <= 1 ? number : factorial(number-1)*number;
}