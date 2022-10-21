#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	{
		std::cout << "\n=== ROUND 1: form creation fail ===" << std::endl;
		try {
			Form noForm("no", 2, 0);
		} catch (Form::GradeTooHighException &e){
			std::cout << "CATCH: " << e.what() << std::endl;
		} catch (Form::GradeTooLowException &e) {
			std::cout << "CATCH: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n=== ROUND 2: beSigned() ===" << std::endl;

		Form hardForm("hard", 1, 1);
		Bureaucrat dobi("dobi", 150);
		Bureaucrat king("king", 1);

		std::cout << " < before >\n" << hardForm << std::endl;

		try {
			hardForm.beSigned(dobi);
		}	catch (Form::GradeTooHighException &e) {
			std::cout << "CATCH: " << e.what() << std::endl;
		} catch (Form::GradeTooLowException &e) {
			std::cout << "CATCH: " << e.what() << std::endl;
		}
		std::cout << " < after dobi try >\n" << hardForm << std::endl;

		try {
			hardForm.beSigned(king);
		}	catch (Form::GradeTooHighException &e) {
			std::cout << "CATCH: " << e.what() << std::endl;
		} catch (Form::GradeTooLowException &e) {
			std::cout << "CATCH: " << e.what() << std::endl;
		}
		std::cout << " < after king try >\n" << hardForm << std::endl;
	}
	{
		std::cout << "\n=== ROUND 3: signForm() ===" << std::endl;

		Bureaucrat dobi("dobi", 90);
		Form hardForm("hard", 1, 1);
		Form easyForm("easy", 100, 100);

		std::cout << "TRY HARD => "; dobi.signForm(hardForm);
		std::cout << "TRY EASY => "; dobi.signForm(easyForm);

	}
}