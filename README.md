# BigInt

BigInt implementation in C++ that stores and operates on arbitrary amount of
integer

## Usage

Run `make run`

```cpp
// Exponent       (^) - Space O(n + m),     Time O(nM)
// Multiplication (*) - Space O(n + m),     Time O(nm)
// Division       (/) - Space O(2(n + m)),  Time O(n^2)
// Modulus        (%) - Space O(2(n + m)),  Time O(n^2)
// Addition       (+) - Space O(1),         Time O(max(n,m))
// Subtraction    (-) - Space O(1),         Time O(max(n,m))

int tmp = -10;

BigInt num1("999999999999999999999999");
BigInt num2(1);
BigInt num3 = tmp;

// Arithmetic operation overloads
std::cout << num1 + num2  << std::endl;
std::cout << num1 - num2  << std::endl;
std::cout << num1 * num2  << std::endl;
std::cout << num1 / num2  << std::endl;
std::cout << num1 % num2  << std::endl;
std::cout << num1++       << std::endl;
std::cout << num2--       << std::endl;
std::cout << ++num1       << std::endl;
std::cout << --num2       << std::endl;

// Member functions
std::cout << BigInt::abs(num3)      << std::endl;
std::cout << num3.abs()             << std::endl;
std::cout << num3.to_string()       << std::endl;
std::cout << num1.to_scientific(3)  << std::endl;
```

Output

```
1000000000000000000000000
999999999999999999999998
999999999999999999999999
999999999999999999999999
0
999999999999999999999999
1
1000000000000000000000001
-1
10
10
-10
100e+22
```

## Test

Don't trust me? Test it yourself.

`make runtest`

or modify `./test/test_bigint.cpp` to your liking before running the test

## TODO

- [ ] Overload more operators
  - [ ] Bit manipulation operators
- [ ] Implement more efficient solution for BigInt division
  - [ ] Implement Karatsuba algorithm for faster multiplication using division

