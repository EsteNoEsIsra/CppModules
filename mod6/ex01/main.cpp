#include "Serializer.h"

int main()
{
    Data *p1 = new Data;
    p1->name = "mario";
    p1->isAlive = true;
    p1->lives = 2;
    p1->coins = 42;
    p1->power = "jump";


    uintptr_t raw = Serializer::serialize(p1);
    std::cout << "P1" << std::endl;
    std::cout << p1->name << std::endl;
    std::cout << p1->isAlive << std::endl;
    std::cout << p1->lives << std::endl;
    std::cout << p1->coins << std::endl;
    std::cout << p1->power << std::endl;


    Data *serializedP1 = Serializer::deserialize(raw);
    
    std::cout << "SerializedP1" << std::endl;
    std::cout << serializedP1->name << std::endl;
    std::cout << serializedP1->isAlive << std::endl;
    std::cout << serializedP1->lives << std::endl;
    std::cout << serializedP1->coins << std::endl;
    std::cout << serializedP1->power << std::endl;

    std::cout << "TEST NULL" << std::endl;
    uintptr_t rawNull = Serializer::serialize(NULL);
    Data* nullPtr = Serializer::deserialize(rawNull);

    std::cout << "Null test: " << nullPtr << std::endl;

    delete p1;


    return 0;
}