#include <iostream>
#include "BigInteger.h"

using namespace std;

int main(){

    BigInteger* one = new BigInteger("1000");
    BigInteger* two = new BigInteger("1");

    one->subtract(two);
    std::cout << "Has to be 999" << std::endl;
    std::cout << one->toString() << std::endl;

    one->add(two);
    std::cout << "Has to be 1000" << std::endl;
    std::cout << one->toString() << std::endl;

    one->multiply(two);
    std::cout << "Not yet implemented" << std::endl;
    std::cout << one->toString() << std::endl;

    one->divide(two);
    std::cout << "Not yet implemented" << std::endl;
    std::cout << one->toString() << std::endl;

    return 0;
}
