#include "Harl.h"

int main()
{
    Harl *harl = new Harl();

    harl->complain("DEBUG");
    harl->complain("INFO");
    harl->complain("WARNING");
    harl->complain("ERROR");

    delete harl;

    return 0;
}