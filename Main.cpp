#include <iostream>
#include "BigInteger.h"

using namespace std;

int main(){

    BigInteger* one = new BigInteger("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    std::cout << one->toString() << std::endl;

    BigInteger* two = new BigInteger("1");

    one->subtract(two);
    std::cout << "Has to be 99...9" << std::endl;
    std::cout << one->toString() << std::endl;

    one->add(two);
    std::cout << "Has to be 100...0" << std::endl;
    std::cout << one->toString() << std::endl;

    one->add(two);
    std::cout << "Has to be 100...1" << std::endl;
    std::cout << one->toString() << std::endl;

    one->multiply(two);
    std::cout << "Not yet implemented" << std::endl;
    std::cout << one->toString() << std::endl;

    one->divide(two);
    std::cout << "Not yet implemented" << std::endl;
    std::cout << one->toString() << std::endl;

    one->mudolo(two);
    std::cout << "Not yet implemented" << std::endl;
    std::cout << one->toString() << std::endl;

    return 0;
}
