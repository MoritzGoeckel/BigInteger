#include <iostream>
#include "BigInteger.h"

using namespace std;

int main(){

    BigInteger* one = new BigInteger("999");
    BigInteger* two = new BigInteger("2");

    one->add(two);

    one->numbers->print();

    return 0;
}
