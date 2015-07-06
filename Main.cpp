#include <iostream>
#include "BigInteger.h"

using namespace std;

void declarationTest() {
    BigInteger* one = new BigInteger("123");
    cout << "-!> 123 = " << one->toString() << endl;
}

void subtractionTest(){
    BigInteger* one = new BigInteger("10");
    BigInteger* two = new BigInteger("2");
    BigInteger* three = new BigInteger("1000");
    BigInteger* four = new BigInteger("8");

    one->subtract(two);
    std::cout << "-!> 8 = " << one->toString() << std::endl;

    std::cout << "-!> 0, 8 = " << one->subtract(three) << ", " << one->toString() << std::endl;

    one->subtract(four);
    std::cout << "-!> 0 = " << one->toString() << std::endl;
}

void additionTest(){
    BigInteger* one = new BigInteger("10");
    BigInteger* two = new BigInteger("2");
    BigInteger* three = new BigInteger("0");

    one->add(two);
    std::cout << "-!> 12 = " << one->toString() << std::endl;

    three->add(two);
    std::cout << "-!> 2 = " << three->toString()  << std::endl;
}

void multiplicationTest(){
    BigInteger* one = new BigInteger("13");
    BigInteger* two = new BigInteger("2");
    BigInteger* three = new BigInteger("0");

    one->multiply(two);
    std::cout << "-!> 26 = " << one->toString() << std::endl;

    one->multiply(three);
    std::cout << "-!> 0 = " << one->toString() << std::endl;

    BigInteger* four = new BigInteger("5");
    BigInteger* five = new BigInteger("5");

    four->multiply(five);
    std::cout << "-!> 25 = " << four->toString() << std::endl;
}

void moduloTest(){
    BigInteger* one = new BigInteger("10");
    BigInteger* two = new BigInteger("3");

    one->modulo(two);
    std::cout << "-!> 1 = " << one->toString() << std::endl;
}

void toPowerOfTest(){
    BigInteger* one = new BigInteger("10");
    BigInteger* two = new BigInteger("3");

    one->toPowerOf(two);
    std::cout << "-!> 1000 = " << one->toString() << std::endl;

    BigInteger* three = new BigInteger("5");
    BigInteger* four = new BigInteger("3");

    three->toPowerOf(four);
    std::cout << "-!> 125 = " << three->toString() << std::endl;
}

int main(){
    declarationTest();
    additionTest();
    subtractionTest();
    multiplicationTest();
    moduloTest();
    toPowerOfTest();

    return 0;
}