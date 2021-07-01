#include <iostream>
#include "bigint/bigint.h"


int main() {
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
}
