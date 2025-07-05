#include "ScalarConverter.hpp"

void print_char(char c)
{
	if (isprint(c))
			std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

float fraction(float value)
{
	return (value - static_cast<int>(value));
}

void print_float(float value)
{
	if (fraction(value) == 0)
		std::cout << "float: " << value << ".0f" << std::endl;
	else
		std::cout << "float: " << value << "f" << std::endl;
}

void print_double(double value)
{
	std::cout << "double: " << value << std::endl;
}

void print_int(int value)
{
	std::cout << "int: " << value << std::endl;
}

void handle_float(const std::string& literal)
{
	float fval;

	fval = std::atof(literal.c_str());
	print_char(static_cast<char>(static_cast<int>(fval)));
	print_int(static_cast<int>(fval));
	print_float(fval);
	print_double(static_cast<double>(fval));
}

void handle_char(const std::string& literal)
{
	int ival;
	print_char(literal[0]);
	ival = static_cast<int>(literal[0]);
	print_int(ival);
	print_float(static_cast<float>(ival));
	print_double(static_cast<double>(ival));
}

void hande_int(const std::string& literal)
{
	int ival;

	ival = (std::atoi(literal.c_str()));
	print_char(static_cast<char>(ival));
	print_int(ival);
	print_float(static_cast<float>(ival));
	print_double(static_cast<double>(ival));
}

void hanle_pseudo(const std::string& literal)
{
	std::string sub;
	char c = 0;
	sub = literal;
	if (literal == "-nan" || literal == "-nanf")
	{
		std::cout << "invalid input" << std::endl;
		return ;
	}
	
	if (get_sign(literal) == -1 || get_sign(literal) == 1)
	{
		sub = literal.substr(1);
		if (get_sign(literal) == -1)
			c = '-';
	}

	if (sub == "inf" || sub == "inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << c << "inf" << "f" << std::endl;
		std::cout << "double: " << c << "inf" << std::endl;
	}

	else if (sub == "nan" || sub == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << "nan" << "f" << std::endl;
		std::cout << "double: " << "nan" << std::endl;
	}
}