#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include <string>
#include <stdint.h>

typedef struct s_Data
{
    std::string name;
    int age;
}Data;

class Serialization
{
    private:
        Serialization();
        ~Serialization();
        Serialization &operator=(Serialization const &other);
        Serialization(Serialization const &other);

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};







#endif