#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() 
	: mGrade(150) {
	std::cout << "Bureaucrat: Default Constructor called" << std::endl;
}

//Any attempt to instantiate a Bureaucrat using an invalid grade,
//must throw an exception.
Bureaucrat::Bureaucrat(const std::string name, int grade) 
	: mName(name), mGrade(grade) {
	std::cout << "Bureaucrat: My Constructor called" << std::endl;
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
		std::cout << "Bureaucrat: Destructor called" << std::endl;
}

const std::string Bureaucrat::getName() const {
	return mName;
}
int Bureaucrat::getGrade() const {
	return mGrade;
}

//If the grade is out of range, both of them will throw exceptions.
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

//--------------------------------------------------------//

Bureaucrat::GradeTooHighException::GradeTooHighException() {
	//std::cout << "(GradeTooHighException: default constructor called.)" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {
	//std::cout << "(GradeTooHighException: destructor called.)" << std::endl;
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {
	//std::cout << "(GradeTooLowException: default constructor called.)" << std::endl;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {
	//std::cout << "(GradeTooLowException: destructor called.)" << std::endl;
}