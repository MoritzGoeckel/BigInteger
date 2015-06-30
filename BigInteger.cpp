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
    add(other->numbers);
}

void BigInteger::add(std::vector<int> other) {
    std::vector<int> newNumbers;

    int remembered = 0;
    int i = 0;
    while ( i < this->numbers.size() || i < other.size())
    {
        int result =   (i < this->numbers.size() ? this->numbers.at(i) : 0)
                       + (i < other.size() ? other.at(i) : 0)
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

void BigInteger::multiply(BigInteger *other) {

    std::vector<std::vector<int>> results;
    for(int i = 0; i < this->numbers.size(); i++)
    {
        std::vector<int> row_result;
        int right = this->numbers.at(i);

        for (int a = 0; a < i; a++)
            row_result.push_back(0);

        int keep = 0;
        for(int a = 0; a < other->numbers.size(); a++)
        {
            int left = other->numbers.at(a);
            int result = (left * right) + keep;

            if(result >= 10){
                keep = 1;
                result = result - 10;
            }
            else
                keep = 0;

            row_result.push_back(result);
        }
        results.push_back(row_result);
    }

    //Alle results addieren
    BigInteger result("0");

    for(int i = 0; i < results.size(); i++)
        result.add(results.at(i));

    this->numbers = result.numbers;
}

void BigInteger::divide(BigInteger *other) {

}

void BigInteger::mudolo(BigInteger *other){

}

std::string BigInteger::toString() {
    std::string output = "";
    for (int i = 0; i < numbers.size(); i++)
        output = std::to_string(numbers.at(i)) + output;
    return output;
}

#endif
