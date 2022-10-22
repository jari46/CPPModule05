#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "arguments should be like: [form type] [dobi's grade] [king's grade]" << std::endl;
		return 0;
	}

	try {
		Bureaucrat dobi("DOBI", std::atoi(argv[2]));
		Bureaucrat king("KING", std::atoi(argv[3]));

		ShrubberyCreationForm shrubForm("CLUSTER");
		RobotomyRequestForm roboForm("CANDY");
		PresidentialPardonForm pardonForm("DOBI");

		switch (std::atoi(argv[1])) {
			case 1 :/* Required grades: sign 145, exec 137 */
				dobi.signForm(shrubForm);
				king.executeForm(shrubForm);
				break ;

			case 2 :/* Required grades: sign 72, exec 45 */
				dobi.signForm(roboForm);
				king.executeForm(roboForm);
				break ;

			case 3 :/* Required grades: sign 25, exec 5 */
				dobi.signForm(pardonForm);
				king.executeForm(pardonForm);
				break ;
			default :
				std::cout << "first argument should be 1 to 3..." << std::endl;
		}
	} catch (const std::exception &e) {
		std::cout << "Why constructing fail: " << e.what() << std::endl;
		return -1;
	}
}