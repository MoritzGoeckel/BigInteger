#ifndef CPP_BIGINTEGER_BIGINTEGER_H
#define CPP_BIGINTEGER_BIGINTEGER_H

#include "BigInteger.h"
#include "ListInt/ListInt.h"

class BigInteger{

    public:
        BigInteger(std::string number);
        void add(BigInteger* number);
        void subtract(BigInteger* number);
        void multiply(BigInteger* number);
        void divide(BigInteger *number);

        ListInt* numbers = 0;
        std::string toString();

};

#endif
