#ifndef BRAIN_H
#define BRAIN_H

#pragma once
#include <iostream>
#include <string>

class Brain
{
    public:
        Brain();
        Brain(const Brain &to_copy);
        Brain &operator=(const Brain &original);
        virtual ~Brain();

    std::string getIdea()const ;
    std::string setIdea()const ;


    private:
        std::string ideas[100];
};

#endif