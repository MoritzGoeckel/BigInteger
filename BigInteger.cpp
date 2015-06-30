#ifndef CPP_BIGINTEGER_BIGINTEGER_IMPLEMENTATION
#define CPP_BIGINTEGER_BIGINTEGER_IMPLEMENTATION

#include <stdlib.h>
#include <iosfwd>
#include "BigInteger.h"

BigInteger::BigInteger(std::string number) {
    for (int i=number.length() - 1;i>=0;i--)
        numbers.push_back(number[i] - '0');
}

void BigInteger::add(BigInteger* other){
    std::vector<int> newNumbers;

    int remembered = 0;
    int i = 0;
    while ( i < this->numbers.size() || i < other->numbers.size())
    {
        int result =   (i < this->numbers.size() ? this->numbers.at(i) : 0)
                     + (i < other->numbers.size() ? other->numbers.at(i) : 0)
                     + (remembered);

        if(result >= 10){
            remembered = 1;
            result = result - 10;
        }
        else
            remembered = 0;

        newNumbers.push_back(result);

        i++;
    }

    if(remembered != 0)
        newNumbers.push_back(remembered);

    this->numbers = newNumbers;
}

void BigInteger::subtract(BigInteger* other) {
    std::vector<int> newNumbers;

    int remembered = 0;
    int i = 0;
    while (i < this->numbers.size() || i < other->numbers.size())
    {
        int result =   (i < this->numbers.size() ? this->numbers.at(i) : 0)
                       - (i < other->numbers.size() ? other->numbers.at(i) : 0)
                       - (remembered);

        if(result < 0){
            remembered = 1;
            result = 10 + result;
        }
        else
            remembered = 0;

        newNumbers.push_back(result);

        i++;
    }

    while (newNumbers.at(newNumbers.size() - 1) == 0)
        newNumbers.pop_back();

    this->numbers = newNumbers;
}

void BigInteger::multiply(BigInteger *number) {

}

void BigInteger::divide(BigInteger *number) {

}

void BigInteger::mudolo(BigInteger *number){

}

std::string BigInteger::toString() {
    std::string output = "";
    for (int i = 0; i < numbers.size(); i++)
        output = std::to_string(numbers.at(i)) + output;
    return output;
}

#endif
