#include <iostream>
#include "Form.h"
#include "Bureaucrat.h"

int main()
{
    try
    {
        Bureaucrat highRank("High Rank", 1);
        Bureaucrat lowRank("Low Rank", 150);

        Form highForm("Top-Secret Form", 1, 1);
        Form lowForm("Standard Form", 150, 150);

        std::cout << highRank << std::endl;
        std::cout << lowRank << std::endl;
        std::cout << highForm << std::endl;
        std::cout << lowForm << std::endl;

        // Attempting to sign forms with both bureaucrats
        highRank.signForm(highForm);
        highRank.signForm(lowForm); // Should succeed
        lowRank.signForm(highForm); // Should fail
        lowRank.signForm(lowForm);  // Should succeed

        std::cout << highForm << std::endl;
        std::cout << lowForm << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
