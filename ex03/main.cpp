#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

/* USAGE: 
	S.F. for ShrubberyCreationForm
	R.F. for RobotomyRequestForm
	P.F. for PresidentialPardonForm */

int main() {
	try {
		Intern stranger;

		Form *shrubForm = stranger.makeForm("S.F.", "CLUSTER");
		Form *roboForm = stranger.makeForm("R.F.", "CANDY");
		Form *pardonForm = stranger.makeForm("P.F.", "DOBI");

		Bureaucrat dobi("DOBI", 25);
		Bureaucrat king("KING", 2);
		
		dobi.signForm(*shrubForm);
		king.executeForm(*shrubForm);

		dobi.signForm(*roboForm);
		king.executeForm(*roboForm);

		dobi.signForm(*pardonForm);
		king.executeForm(*pardonForm);

		Form *wrongForm = stranger.makeForm("F.F.", "HIHI");/* throw exception */
		dobi.signForm(*wrongForm);/* not working */
		king.executeForm(*wrongForm);/* not working */
	} catch (const std::exception &e) {
    std::cout << "Why main() failed: " << e.what() << std::endl;
  }
}