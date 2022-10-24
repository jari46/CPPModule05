#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() 
	: mGrade(150) {
	//std::cout << "Bureaucrat: Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) 
	: mName(name), mGrade(grade) {
	//std::cout << "Bureaucrat: My Constructor called" << std::endl;
	if (grade < GRADE_MAX)
		throw GradeTooHighException();
	if (grade > GRADE_MIN)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) {
	//std::cout << "Bureaucrat: Copy constructor called" << std::endl;
	(*this) = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
	//std::cout << "Bureaucrat: Copy assignment operator called" << std::endl;
	if (this != &src) {
		//mName attribute is constant.
		mGrade = src.mGrade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
		//std::cout << "Bureaucrat: Destructor called" << std::endl;
}

//----------------------------------------------------------------------//

const std::string Bureaucrat::getName() const {
	return mName;
}
int Bureaucrat::getGrade() const {
	return mGrade;
}

void Bureaucrat::incrementingGrade() {
	if (mGrade - 1 < GRADE_MAX)
		throw GradeTooHighException();
	else
		--mGrade;
}

void Bureaucrat::decrementingGrade() {
	if (mGrade + 1 > GRADE_MIN)
		throw GradeTooLowException();
	else
		++mGrade;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b) {
	os << b.getName() << ": bureaucrat grade " << b.getGrade() << std::endl;
	return os;
}

void Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << mName << " -> " << form.getName() << " SIGN SUCCESS!! (^_^)" << std::endl;
	} catch (std::exception &e) {
		std::cout << mName << " -> " << form.getName() << " SIGN FAIL (ㅠ_ㅠ): " << e.what() << std::endl;
	}
}

//attempt to execute the form
void Bureaucrat::executeForm(const Form &form) const {
	try {
		form.execute(*this);
		std::cout << mName << " -> " << form.getName() << " EXECUTE SUCCESS!! (^_^)" << std::endl;
	} catch (const std::exception &e) {
				std::cout << mName << " -> " << form.getName() << " EXECUTE FAIL (ㅠ_ㅠ): " << e.what() << std::endl;

	}
}

//--------------------------------------------------------//

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}
