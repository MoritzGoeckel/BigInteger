#ifndef CPP_BIGINTEGER_BIGINTEGER_IMPLEMENTATION
#define CPP_BIGINTEGER_BIGINTEGER_IMPLEMENTATION

#include <stdlib.h>
#include "BigInteger.h"

BigInteger::BigInteger(std::string number) {
    this->numbers = new ListInt();

    for (int i=0;i<number.length();i++)
        numbers->insert(number[i] - '0', 0);
}

void BigInteger::add(BigInteger* number){
    IteratorInt* thisIterator = this->numbers->getIterator();
    IteratorInt* otherIterator = number->numbers->getIterator();

    ListInt* newNumbers = new ListInt();

    int remembered = 0;
    while (thisIterator->hasNext()|| otherIterator->hasNext())
    {
        int result = thisIterator->getNext() + otherIterator->getNext() + remembered;
        if(result >= 10){
            remembered = 1;
            result = result - 10;
        }
        else
            remembered = 0;

        newNumbers->add(result);
    }

    newNumbers->add(remembered);

    delete(this->numbers);

    this->numbers = newNumbers;
}

void BigInteger::subtract(BigInteger* number) {
    IteratorInt* thisIterator = this->numbers->getIterator();
    IteratorInt* otherIterator = number->numbers->getIterator();

    ListInt* newNumbers = new ListInt();

    int remembered = 0;
    while (thisIterator->hasNext()|| otherIterator->hasNext())
    {
        int result = thisIterator->getNext() - otherIterator->getNext() - remembered;
        if(result < 0){
            remembered = 1;
            result = 10 + result;
        }
        else
            remembered = 0;

        newNumbers->add(result);
    }

    delete(this->numbers);

    this->numbers = newNumbers;
}

void BigInteger::multiply(BigInteger* number) {

}

void BigInteger::devide(BigInteger* number) {

}

std::string BigInteger::toString() {
    std::string output = "";
    IteratorInt* iterator = this->numbers->getIterator();
    while (iterator->hasNext())
        output = std::to_string(iterator->getNext()) + output;
    return output;
}

#endif
