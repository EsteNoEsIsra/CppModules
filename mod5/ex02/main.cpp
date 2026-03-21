#include "Bureaucrat.h"
#include "AForm.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

int main(void)
{
    std::srand(time(0));
    try
    {
        Bureaucrat boss("Mariano", 3);
        Bureaucrat bur("paco", 150);

        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Zaphod Beeblebrox");

        std::cout << "--- Test 1: Intento de ejecución sin firma ---" << std::endl;
        try {
            boss.executeForm(shrubbery);
        } catch (std::exception &e) {
            std::cerr << "Error esperado: " << e.what() << std::endl;
        }

        std::cout << "\n--- Test 2: Firma de formularios ---" << std::endl;
        boss.signForm(shrubbery);
        boss.signForm(robotomy);
        boss.signForm(pardon);

        std::cout << "\n--- Test 3: Ejecución correcta (Shrubbery) ---" << std::endl;
        boss.executeForm(shrubbery); // Debería crear el archivo home_shrubbery

        std::cout << "\n--- Test 4: Ejecución con 50% probabilidad (Robotomy) ---" << std::endl;
        boss.executeForm(robotomy);
        boss.executeForm(robotomy);
        boss.executeForm(robotomy);
        boss.executeForm(robotomy); // Probar varias veces para ver el random

        std::cout << "\n--- Test 5: Ejecución presidencial (Pardon) ---" << std::endl;
        boss.executeForm(pardon);

        std::cout << "\n--- Test 6: Burócrata con grado insuficiente ---" << std::endl;
        try {
            bur.executeForm(pardon);
        } catch (std::exception &e) {
            std::cerr << "Error esperado: " << e.what() << std::endl;
        }

    }
    catch(std::exception &e)
    {
        std::cerr << RED << "Error: " << e.what() << RESET <<std::endl;
    }


    return 0;
}