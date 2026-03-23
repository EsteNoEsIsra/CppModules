#include "Bureaucrat.h"
#include "AForm.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include "Intern.h"

int main(void)
{
    std::srand(time(0));
    try
    {
        Bureaucrat boss("Mariano", 3);
       
        std::cout << "\n--- Test 7: Pruebas del Intern ---" << std::endl;
        
        Intern sadIntern;
        AForm* rrf;
        AForm* scf;
        AForm* ppf;
        AForm* unknown;

        rrf = sadIntern.makeForm("Robotomy Request", "Bender");
        if (rrf)
        {
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf;
        }
        std::cout << std::endl;

        scf = sadIntern.makeForm("Shrubbery Creation", "Garden");
        if (scf)
        {
            boss.signForm(*scf);
            boss.executeForm(*scf);
            delete scf;
        }

        std::cout << std::endl;

        ppf = sadIntern.makeForm("Presidential Pardon", "Criminal");
        if (ppf)
        {
            boss.signForm(*ppf);
            boss.executeForm(*ppf);
            delete ppf;
        }

        std::cout << std::endl;
        unknown = sadIntern.makeForm("declaracion de la renta", "Target");
        if (!unknown) 
        {
            std::cout << "El Intern no pudo crear el formulario (main)." << std::endl;
        }
    }
    catch(std::exception &e)
    {
        std::cerr << RED << "Error: " << e.what() << RESET <<std::endl;
    }


    return 0;
}