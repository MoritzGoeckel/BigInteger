# BigInteger in C++
This is a BigInteger implementation for C++. It supports operations on unlimited big numbers. 

### Supported operations:
- Addition
- Subtraction
- Multiplication
- Modulo
- Power of n

### Yet unsupported:
- Division

## Usage:
```cpp
 BigInteger* one = new BigInteger("123");
 BigInteger* two = new BigInteger("123");
 
 //Output the number
 std::cout << one->toString() << std::endl;
 
 //Simple substraction
 one->subtract(two);
 std::cout << one->toString() << std::endl;

 //Simple addition
 one->add(two);
 std::cout << one->toString() << std::endl;

 //Simple multiplication
 one->multiply(three);
 std::cout << one->toString() << std::endl;

 //Subtraction that will fail, because this library does not support negative numbers.
 std::cout << two->subtract(new BigInteger("1000000000000000000000")) << std::endl; //This will return 0 or false
 std::cout << two->toString() << std::endl; //The number will not be modified

 //Simple modulo
 one->modulo(two);
 std::cout << one->toString() << std::endl;

 //Power of
 one->toPowerOf(two);
 std::cout << one->toString() << std::endl;
```
