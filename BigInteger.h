#ifndef CPP_BIGINTEGER_BIGINTEGER_H
#define CPP_BIGINTEGER_BIGINTEGER_H

#include <string>
#include <vector>
#include "BigInteger.h"

class BigInteger{

    public:
        BigInteger(std::string number);
        BigInteger(BigInteger* otherInteger);

        void add(BigInteger* other);
        void add(std::vector<int> other);

        bool subtract(BigInteger* other);
        bool subtract(std::vector<int> other);

        void multiply(BigInteger* other);

        //void divide(BigInteger *other);
        void modulo(BigInteger *other);

        void powerOf(BigInteger *other);

        std::vector<int> numbers;
        std::string toString();

    private:
        void declareFromString(std::string number);

};

#endif
