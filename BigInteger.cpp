#ifndef CPP_BIGINTEGER_BIGINTEGER_IMPLEMENTATION
#define CPP_BIGINTEGER_BIGINTEGER_IMPLEMENTATION

#include <stdlib.h>
#include <iosfwd>
#include <iostream>
#include "BigInteger.h"

BigInteger::BigInteger(std::string number) {
    declareFromString(number);
}

BigInteger::BigInteger(BigInteger *otherInteger) {
    declareFromString(otherInteger->toString());
}

void BigInteger::declareFromString(std::string number) {
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
        //Use the next right number
        std::vector<int> row_result;
        int rightNumber = this->numbers.at(i);

        //Fill the row_results with 0's according to the position of rightNumber
        for (int a = 0; a < i; a++)
            row_result.push_back(0);

        //Do the multiplication on every leftNumber with the one rightNumber
        int remembered = 0;
        for(int a = 0; a < other->numbers.size(); a++)
        {
            int leftNumber = other->numbers.at(a);
            int result = (leftNumber * rightNumber) + remembered;

            if(result >= 10){
                remembered = 1;
                result = result - 10;
            }
            else
                remembered = 0;

            row_result.push_back(result);
        }
        results.push_back(row_result);
    }

    //Add all results
    BigInteger result("0");
    for(int i = 0; i < results.size(); i++)
        result.add(results.at(i));

    while (result.numbers.size() > 1 && result.numbers.at(result.numbers.size() - 1) == 0)
        result.numbers.pop_back();

    this->numbers = result.numbers;
}

/*void BigInteger::divide(BigInteger *other) {

}*/

void BigInteger::modulo(BigInteger *other){

    //If: (other > this) Then: result = this So: there is nothing to do
    if(this->subtract(other) == false)
        return;

    //Copy array of other (the smaller number)
    std::vector<int> otherTmp;
    for(int i = 0; i < other->numbers.size(); i++)
        otherTmp.push_back(other->numbers.at(i));

    //Save the length, because we are going to add and remove 0's, and we have to go back in the end
    int initialLength = otherTmp.size();

    //Try to approximate by adding 0's (multiplying by 10)
    while (this->numbers.size() > otherTmp.size())
        otherTmp.insert(otherTmp.begin(), 0); //Add 0 at beginning

    while (otherTmp.size() >= initialLength) {
        while (this->subtract(otherTmp)); //Subtract as much as possible
        otherTmp.erase(otherTmp.begin()); //Remove one 0 (= divide by 10)
    }
}

std::string BigInteger::toString() {
    std::string output = "";
    for (int i = 0; i < numbers.size(); i++)
        output = std::to_string(numbers.at(i)) + output;
    return output;
}

void BigInteger::toPowerOf(BigInteger *other) {
    BigInteger* otherInteger = new BigInteger(other);

    BigInteger* oldValue = new BigInteger(this->toString());

    BigInteger* one = new BigInteger("1");
    while (!(otherInteger->numbers.size() == 1 && otherInteger->numbers.at(0) == 1))
    {
        /*std::cout << "NOW = " << this->toString() << std::endl;
        std::cout << "I = " << otherInteger->toString() << std::endl;
        std::cout << "OLD = " << oldValue->toString() << std::endl;*/

        this->multiply(oldValue);
        otherInteger->subtract(one);
    }

    delete one;
    delete otherInteger;
    delete oldValue;
}

#endif
