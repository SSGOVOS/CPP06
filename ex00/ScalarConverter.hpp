#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP


#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <sstream>



class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();
    
        ScalarConverter &operator=(ScalarConverter const &other);
        ScalarConverter(ScalarConverter const &other);
        
    public:

        static bool isChar(const std::string &literal);
        static bool isInt(const std::string &literal);
        static bool isDouble(const std::string &literal);



        
        static void convert(std::string literal);
};




#endif