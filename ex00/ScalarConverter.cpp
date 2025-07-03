#include "ScalarConverter.hpp"

bool ScalarConverter::isChar(const std::string &literal)
{
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'' )
    {
        char c = literal[1];
        return std::isprint(static_cast<unsigned char>(c));
    }
    return false;
}

bool ScalarConverter::isInt(const std::string &literal)
{
    if (literal.empty())
        return false;
    size_t i = 0;
    if (literal[i] == '+' || literal[i] == '-')
    {
        i++;
        if (i == literal.size())
            return false;
    }
    for(; i < literal.size(); i++)
    {
        if (!std::isdigit(literal[i]))
            return false;
    }
    try
    {
        long value = std::stol(literal);
        if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
            return false;
        return true;
    }
    catch(...)
    {
        return false;
    }
}
bool ScalarConverter::isDouble(const std::string &literal)
{
    if (literal == "+inf" || literal == "-inf" || literal == "nan")
        return true;
    
    if (literal.empty())
        return false;
    
    size_t i = 0;

    if (literal[i] == '+' || literal[i] == '-')
    {
        i++;
        if (i == literal.size())
            return false;
    }
    
    bool dotFound = false;
    bool digitFound = false;

    for (; i < literal.size(); i++)
    {
        if (literal[i] == '.')
        {
            if (dotFound)
                return false;
            dotFound = true;
        }
        else if (std::isdigit(literal[i]))
            digitFound = true;
        else
            return false;
    }
    
    if (!digitFound || !dotFound)
        return false;

    try{
        std::stod(literal);
        return true;
    }
    catch(...){
        return false;
    }
}


// bool isPseudoFloat(const std::string& literal) 
// {
//     if(literal == "-inff" || literal == "+inff" || literal == "nanf")
//         return true;
//     return false;
// }

// bool isFloat(const std::string &literal)
// {
//     if (isPseudoFloat(literal))
//         return true;

//     if (literal.empty() || literal.back() != 'f')
//         return false;


//     std::string numPart = literal.substr(0 , literal.size() - 1);
//     if (numPart.empty())
//         return false;

//     size_t i = 0;
//     if (numPart[i] == '+' || numPart[i] == '-')
//     {
//         i++;
//         if (i >= numPart.size())
//             return false;
//     } 
// }


// void ScalarConverter::convert(std::string literal)
// {
// }