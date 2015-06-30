#include <iostream>
#include "BigInteger.h"

using namespace std;

int main(){

    BigInteger* one = new BigInteger("123");
    std::cout << "-!> 123" << std::endl;
    std::cout << one->toString() << std::endl;

    BigInteger* two = new BigInteger("5");

    BigInteger* three = new BigInteger("120");

    one->subtract(two);
    std::cout << "-!> 118" << std::endl;
    std::cout << one->toString() << std::endl;

    one->add(two);
    std::cout << "-!> 123" << std::endl;
    std::cout << one->toString() << std::endl;

    one->multiply(three);
    std::cout << "-!> 14760" << std::endl;
    std::cout << one->toString() << std::endl;

    std::cout << "-!> 0, 5" << std::endl;
    std::cout << two->subtract(three) << std::endl;
    std::cout << two->toString() << std::endl;

    //one->divide(two);
    //std::cout << "Not yet implemented" << std::endl;
    //std::cout << one->toString() << std::endl;

    BigInteger* oneHundred = new BigInteger("34567890");
    BigInteger* four = new BigInteger("45678");

    oneHundred->mudolo(four);
    std::cout << "-!> 35322" << std::endl;
    std::cout << oneHundred->toString() << std::endl;

    return 0;
}
