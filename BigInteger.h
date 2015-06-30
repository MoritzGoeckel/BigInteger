#ifndef CPP_BIGINTEGER_BIGINTEGER_H
#define CPP_BIGINTEGER_BIGINTEGER_H

#include <string>
#include <vector>
#include "BigInteger.h"

class BigInteger{

    public:
        BigInteger(std::string number);
        void add(BigInteger* number);
        void subtract(BigInteger* number);
        void multiply(BigInteger* number);
        void divide(BigInteger *number);
        void mudolo(BigInteger *number);

        std::vector<int> numbers;
        std::string toString();

};

#endif
