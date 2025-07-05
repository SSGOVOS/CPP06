#pragma once

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& other);
	public:
		static void convert(const std::string& literal);
};

void handle_float(const std::string& literal);
void print_char(char c);
void handle_char(const std::string& literal);
void hande_int(const std::string& literal);
void hanle_pseudo(const std::string& literal);
int get_sign(const std::string& literal);