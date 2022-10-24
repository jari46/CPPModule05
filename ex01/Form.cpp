#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() 
	: mSigned(false), mGradeRequiredToSign(1), mGradeRequiredToExecute(1) {
	std::cout << "Form: Default Constructor called" << std::endl;
}

//Any attempt to instantiate a Form using an invalid grade,
//must throw an exception.
Form::Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute) 
	: mName(name), mSigned(false), mGradeRequiredToSign(gradeRequiredToSign), mGradeRequiredToExecute(gradeRequiredToExecute) {
	std::cout << "Form: My Constructor called" << std::endl;
	if (mGradeRequiredToSign < GRADE_MAX || mGradeRequiredToExecute < GRADE_MAX)
		throw GradeTooHighException();
	if (mGradeRequiredToSign > GRADE_MIN || mGradeRequiredToExecute > GRADE_MIN)
		throw GradeTooLowException();
}

Form::Form(const Form& src) 
	: mName(src.getName()), mSigned(src.getSigned()), \
	mGradeRequiredToSign(src.getGradeRequiredToSign()), \
	mGradeRequiredToExecute(src.getGradeRequiredToExecute()) {
	//std::cout << "Form: Copy constructor called" << std::endl;
}

//recommend to not use
Form& Form::operator=(const Form& src) {
	//std::cout << "Form: Copy assignment operator called" << std::endl;
	if (this != &src) {
		setSigned(src.getSigned());
		//other attribute is all constant.
	}
	return *this;
}

Form::~Form() {
		std::cout << "Form: Destructor called" << std::endl;
}

std::string Form::getName() const {
	return mName;
}

bool Form::getSigned() const {
	return mSigned;
}

int Form::getGradeRequiredToSign() const {
	return mGradeRequiredToSign;
}

int Form::getGradeRequiredToExecute() const {
	return mGradeRequiredToExecute;
}

void Form::setSigned(int sign) {
	mSigned = sign;
}

void Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > mGradeRequiredToSign)
		throw GradeTooLowException();
	else
		mSigned = true;
}

std::ostream &operator<<(std::ostream &os, Form const &b) {
	os << " * Name: " << b.getName()  << std::endl \
	<< " * Signed: " << b.getSigned()  << std::endl \
	<< " * Grade required to sign: " << b.getGradeRequiredToSign()  << std::endl \
	<< " * Grade required to execute: " << b.getGradeRequiredToExecute() << std::endl;
	return os;
}

//--------------------------------------------------------//

const char* Form::GradeTooHighException::what() const throw() {
	return "the grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "the grade is too low!";
}
