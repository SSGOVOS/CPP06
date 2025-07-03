#include "ScalarConverter.hpp"


int main()
{
    std::string s1 = "42";
    std::string s2 = "-123";
    std::string s3 = "4.2";

    std::cout << ScalarConverter::isInt(s1) << std::endl; // true
    std::cout << ScalarConverter::isInt(s2) << std::endl; // true
    std::cout << ScalarConverter::isInt(s3) << std::endl; // false

}