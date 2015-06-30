#ifndef CPP_BIGINTEGER_BIGINTEGER_H
#define CPP_BIGINTEGER_BIGINTEGER_H

#include <string>
#include <vector>
#include "BigInteger.h"

class BigInteger{

    public:
        BigInteger(std::string number);

        void add(BigInteger* other);
        void add(std::vector<int> other);

        bool subtract(BigInteger* other);
        bool subtract(std::vector<int> other);

        void multiply(BigInteger* other);

        void divide(BigInteger *other);
        void mudolo(BigInteger *other);

        std::vector<int> numbers;
        std::string toString();

};

#endif
