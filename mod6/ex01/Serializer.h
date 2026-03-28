#ifndef SERIALIZER_H
#define SERIALIZER_H

#pragma once
#include <iostream>
# include <stdint.h>
#include "Data.h"

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer *to_copy);
        Serializer &operator=(const Serializer &original);
        ~Serializer();
    public:
    	static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

};

#endif