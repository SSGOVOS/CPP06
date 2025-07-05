#include "ScalarConverter.hpp"


ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void) other;
	return (*this);
}

int get_sign(const std::string& literal)
{
	if (literal[0] == '-')
		return (-1);
	if (literal[0] == '+')
		return (1);
	return (0);
}

int count_c(const std::string& literal, char c)
{
	int count = 0;
	int start = 0;
	if (get_sign(literal) == -1 || get_sign(literal) == 1)
		start = 1;
	for (size_t i = start; i < literal.size(); i++)
	{
		if (literal[i] == c)
			count++;
	}
	return (count);
}

bool check_nan(const std::string& literal)
{
	std::string sub;
	if (get_sign(literal) == -1 || get_sign(literal) == 1)
		sub = literal.substr(1);
	else
		sub = literal;
	if (sub == "nan" || sub == "nanf")
		return (true);
	return (false);
}

bool check_inf(const std::string& literal)
{
	std::string sub;
	if (get_sign(literal) == -1 || get_sign(literal) == 1)
		sub = literal.substr(1);
	else
		sub = literal;
	if (sub == "inf" || sub == "inff")
		return (true);
	return (false);
}

bool is_valid(const std::string& literal, bool* nan)
{
	int start = 0;
	int sign = 0;
	if (literal.size() == 1)
		return (true);
	if (check_nan(literal) || check_inf(literal))
	{
		*nan = true;
		return (true);
	}
	sign = get_sign(literal);
	if (sign == -1 || sign == 1)
		start = 1;
	for (size_t i = start; i < literal.length(); i++)
	{
		if (!std::isdigit(literal[i]) && literal[i] != '.' && literal[literal.size() - 1] != 'f')
			return (false);
	}
	return(true);
}

bool check_all_num(const std::string& literal)
{
	int sign = get_sign(literal);
	int start = 0;
	if (sign == -1 || sign  == 1)
		start = 1;
	for (size_t i = start; i < literal.length(); i++)
	{
		if (!std::isdigit(literal[i]))
			return (false);
	}
	return (true);
}

int classify(const std::string& literal)
{
	if (literal.size() == 1 && !std::isdigit(literal[0]))
		return (0);
	if (count_c(literal, '.') == 1 && count_c(literal, 'f') <= 1)
	{
		if(literal[literal.size() - 1] == 'f')
		{
			if (literal.find('.') < literal.find('f'))
				return (1);
		}
		else 
			return(-1);
	}
	if (check_all_num(literal))
		return (2);
	return(-1);
}

void ScalarConverter::convert(const std::string& literal)
{
	
	int type;
	bool nan = false;
	if (!is_valid(literal ,&nan))
	{
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	if (nan)
	{
		hanle_pseudo(literal);
		return;
	}
	type = classify(literal);
	switch (type)
	{
		case 0:
			handle_char(literal);
			break;;
		case 1 :
			handle_float(literal);
			break;
		case 2:
			hande_int(literal);
			break;
		case -1:
			std::cout << "Invalid input" << std::endl;
			break;
		
	}
}