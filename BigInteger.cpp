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

bool BigInteger::subtract(BigInteger* other) {
    return subtract(other->numbers);
}

bool BigInteger::subtract(std::vector<int> other) {
    std::vector<int> newNumbers;

    int remembered = 0;
    int i = 0;
    while (i < this->numbers.size() || i < other.size() || remembered != 0)
    {
        if(i >= this->numbers.size() && i >= other.size() && remembered != 0)
            return false; //Subtraction was impossible

        int result =   (i < this->numbers.size() ? this->numbers.at(i) : 0)
                       - (i < other.size() ? other.at(i) : 0)
                       - (remembered);

        remembered = 0;

        if(result < 0){
            while (result < 0) {
                result = result + 10;
                remembered++;
            }
        }

        newNumbers.push_back(result);

        i++;
    }

    while (newNumbers.size() > 1 && newNumbers.at(newNumbers.size() - 1) == 0)
        newNumbers.pop_back();

    this->numbers = newNumbers;

    return true; //Subtraction was possible
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
    if(this->subtract(other) == false)
        return;

    //Copy array
    std::vector<int> otherTmp;
    for(int i = 0; i < other->numbers.size(); i++)
        otherTmp.push_back(other->numbers.at(i));

    int initialLength = otherTmp.size();

    //Try to approximate
    while (this->numbers.size() > otherTmp.size())
        otherTmp.insert(otherTmp.begin(), 0); //Add 0 at beginning

    int s = otherTmp.size();
    int d = this->numbers.size();

    while (otherTmp.size() >= initialLength) {
        while (this->subtract(otherTmp)); //Subtract as much as possible
        otherTmp.erase(otherTmp.begin());
    }
}

std::string BigInteger::toString() {
    std::string output = "";
    for (int i = 0; i < numbers.size(); i++)
        output = std::to_string(numbers.at(i)) + output;
    return output;
}

#endif
