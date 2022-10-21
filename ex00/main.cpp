#include <iostream>
#include "Bureaucrat.hpp"

int main() {
	{
		std::cout << "\n=== ROUND 1: increment ===" << std::endl;
		try {
			Bureaucrat dobi("dobi", 2);
			std::cout << "* before: " << dobi;
			try {
					for (int i = 0; i < 2; ++i)
						dobi.incrementingGrade();
			} catch (Bureaucrat::GradeTooHighException& e) {
				std::cout << "CATCH: " << e.what() << std::endl;
			}
			std::cout << "* after: " << dobi;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << "CATCH: " << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << "CATCH: " << e.what() << std::endl;
		}
	{
		std::cout << "\n=== ROUND 2: decrement ===" << std::endl;
		try {
			Bureaucrat dobi("dobi", 147);
			std::cout << "* before: " << dobi;
			try {
					for (int i = 0; i < 10; ++i)
						dobi.decrementingGrade();
			} catch (Bureaucrat::GradeTooLowException& e) {
				std::cout << "CATCH: " << e.what() << std::endl;
			} catch (Bureaucrat::GradeTooHighException& e) {
				std::cout << "CATCH: " << e.what() << std::endl;
			}
				std::cout << "* after: " << dobi;
			} catch (Bureaucrat::GradeTooLowException& e) {
				std::cout << "CATCH: " << e.what() << std::endl;
			} catch (Bureaucrat::GradeTooHighException& e) {
				std::cout << "CATCH: " << e.what() << std::endl;
			}
		}
	}
}